#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <tuple>
#include <climits>
using namespace std;

int solution(string begin, string target, vector<string> words) {
	// 최소값을 구할 변수로 INT_MAX로 초기화
	int answer = INT_MAX;

	// queue<tuple<(이전에 비교되어서 삭제된 후의 string vector), 현재 비교해야될 string, 현재까지의 비교횟수>>
	queue<tuple<vector<string>, string, int>> que;

	// 초기상태 push
	que.push(make_tuple(words, begin, 0));

	// bfs 탐색
	while (!que.empty()) {
		vector<string> curVec = get<0>(que.front());
		string curStr = get<1>(que.front());
		int curCnt = get<2>(que.front());

		// 현재 상태값을 저장 후 pop
		que.pop();

		// 현재 비교해야될 string이 target string과 같을 경우 탐색종료
		if (curStr.compare(target) == 0) {
			answer = curCnt;
			break;
		}

		for (int i = 0; i < curVec.size(); i++) {
			// 문자 하나가 불일치 할 경우에 단어변환이 가능하므로 문자가 일치하는 개수를 count해주는 변수 초기화 
			int charCmp = 0;

			// 현재 비교대상 string과 vector string의 인덱스별로 char 한개씩 비교
			for (int j = 0; j < curStr.size(); j++) {
				if (curStr[j] == curVec[i][j]) {
					charCmp++;
				}
			}

			// char일치 개수가 1개가 불일치 하였을 경우 단어변환이 가능하여 다음 탐색을 위해 queue에 push
			if (charCmp + 1 == curStr.size()) {
				vector<string> tempVec = curVec;
				vector<string>::iterator iter = tempVec.begin() + i;
				tempVec.erase(iter);
				que.push(make_tuple(tempVec, curVec[i], curCnt + 1));
			}
		}
	}

	// 단어변환이 일어나지 않았을 경우 초기 INT_MAX값을 0으로 변경
	if (answer == INT_MAX) {
		answer = 0;
	}

	return answer;
}