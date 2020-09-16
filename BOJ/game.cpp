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
	// �־��� �������� ��ǥ������ ��� ��� 0 ��ȯ
	if (row < 0 || row >= N || col < 0 || col >= M) {
		return 0;
	}

	// dfs���� �� ��ο� ���� �̹� ���� Ž���Ͽ��� ��� ���ѹ� ������ �� �ִ� ��찡 �����ϹǷ� -1�� ��� �� ����
	if (visited[row][col]) {
		cout << -1 << endl;
		exit(0);
	}

	// ���� ���ۿ� ������ ��� -1 ��ȯ
	if (numVec[row][col] == -1) {
		return 0;
	}

	// ���� ��ǥ���� �湮�ϸ鼭 �����Ǿ��� Ƚ���� ���� ������ ����
	int &cnt = dp[row][col];

	// �����Ǿ��� �̷��� ���� ��� ������ �״�� ��ȯ
	if (cnt != 0) {
		return cnt;
	}

	// ���� ��ġ �湮 ����
	visited[row][col] = true;

	// ��, ��, ��, �� ��� ��쿡 ���� Ž��
	for (int i = 0; i < 4; i++) {
		cnt = maxNum(cnt, dfs(row + numVec[row][col] * dir[i][0], col + numVec[row][col] * dir[i][1]) + 1);
	}

	// �� ��ο� ���� Ž���� �������Ƿ� ���� ��� Ž���� ���� ���� ��ġ �湮������ false�� ����
	visited[row][col] = false;

	return cnt;
}

int main() {
	string numStr;
	// �ʱ� input data�� 1���� string vector�� ������ ���� ����
	vector<string> numStrVec;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> numStr;
		for (int j = 0; j < M; j++) {
			// ���� �� char�� ������ �ƴ� ���
			if (numStr[j] != 'H') {
				// '1' - '0' = 1
				numVec[i][j] = numStr[j] - '0';
			}
			// ������ ��ġ�� 'H' ��� -1 ����
			else {
				numVec[i][j] = -1;
			}
		}
	}
	// dfsŽ�� �� ���������� ��ȯ�� ������ ���
	cout << dfs(0, 0) << endl;
	return 0;
}