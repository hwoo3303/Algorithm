#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <tuple>
#include <climits>
using namespace std;

int solution(string begin, string target, vector<string> words) {
	// �ּҰ��� ���� ������ INT_MAX�� �ʱ�ȭ
	int answer = INT_MAX;

	// queue<tuple<(������ �񱳵Ǿ ������ ���� string vector), ���� ���ؾߵ� string, ��������� ��Ƚ��>>
	queue<tuple<vector<string>, string, int>> que;

	// �ʱ���� push
	que.push(make_tuple(words, begin, 0));

	// bfs Ž��
	while (!que.empty()) {
		vector<string> curVec = get<0>(que.front());
		string curStr = get<1>(que.front());
		int curCnt = get<2>(que.front());

		// ���� ���°��� ���� �� pop
		que.pop();

		// ���� ���ؾߵ� string�� target string�� ���� ��� Ž������
		if (curStr.compare(target) == 0) {
			answer = curCnt;
			break;
		}

		for (int i = 0; i < curVec.size(); i++) {
			// ���� �ϳ��� ����ġ �� ��쿡 �ܾȯ�� �����ϹǷ� ���ڰ� ��ġ�ϴ� ������ count���ִ� ���� �ʱ�ȭ 
			int charCmp = 0;

			// ���� �񱳴�� string�� vector string�� �ε������� char �Ѱ��� ��
			for (int j = 0; j < curStr.size(); j++) {
				if (curStr[j] == curVec[i][j]) {
					charCmp++;
				}
			}

			// char��ġ ������ 1���� ����ġ �Ͽ��� ��� �ܾȯ�� �����Ͽ� ���� Ž���� ���� queue�� push
			if (charCmp + 1 == curStr.size()) {
				vector<string> tempVec = curVec;
				vector<string>::iterator iter = tempVec.begin() + i;
				tempVec.erase(iter);
				que.push(make_tuple(tempVec, curVec[i], curCnt + 1));
			}
		}
	}

	// �ܾȯ�� �Ͼ�� �ʾ��� ��� �ʱ� INT_MAX���� 0���� ����
	if (answer == INT_MAX) {
		answer = 0;
	}

	return answer;
}