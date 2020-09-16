#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> numVec(60, vector<int>(60, 0));
vector<vector<bool>> visited(60, vector<bool>(60, false));
int dp[60][60];
int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
int result;
int Max;
int N, M;

int maxNum(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int dfs(int row, int col) {
	// 주어진 보드판의 좌표범위를 벗어날 경우 0 반환
	if (row < 0 || row >= N || col < 0 || col >= M) {
		return 0;
	}

	// dfs에서 한 경로에 대해 이미 전에 탐색하였을 경우 무한번 움직일 수 있는 경우가 존재하므로 -1을 출력 후 종료
	if (visited[row][col]) {
		cout << -1 << endl;
		exit(0);
	}

	// 공이 구멍에 빠졌을 경우 -1 반환
	if (numVec[row][col] == -1) {
		return 0;
	}

	// 현재 좌표에서 방문하면서 누적되었던 횟수에 대한 참조자 선언
	int &cnt = dp[row][col];

	// 누적되었던 이력이 있을 경우 누적값 그대로 반환
	if (cnt != 0) {
		return cnt;
	}

	// 현재 위치 방문 저장
	visited[row][col] = true;

	// 동, 서, 남, 북 모든 경우에 대한 탐색
	for (int i = 0; i < 4; i++) {
		cnt = maxNum(cnt, dfs(row + numVec[row][col] * dir[i][0], col + numVec[row][col] * dir[i][1]) + 1);
	}

	// 한 경로에 대한 탐색을 끝냈으므로 다음 경로 탐색을 위해 현재 위치 방문변수를 false로 변경
	visited[row][col] = false;

	return cnt;
}

int main() {
	string numStr;
	// 초기 input data를 1차원 string vector로 저장할 변수 선언
	vector<string> numStrVec;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> numStr;
		for (int j = 0; j < M; j++) {
			// 현재 비교 char가 구멍이 아닐 경우
			if (numStr[j] != 'H') {
				// '1' - '0' = 1
				numVec[i][j] = numStr[j] - '0';
			}
			// 구멍의 위치에 'H' 대신 -1 저장
			else {
				numVec[i][j] = -1;
			}
		}
	}
	// dfs탐색 후 최종적으로 반환될 변수를 출력
	cout << dfs(0, 0) << endl;
	return 0;
}