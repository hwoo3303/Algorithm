#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

	// 테스트 케이스 단위 반복문
    for (int tc = 1; tc <= T; tc++) {
        int answer = 0;
        double N;

        cin >> N;

		// N이 2가 될때까지 반복
        while(N != 2){
			// 현재 N의 제곱근이 정수일 경우
        	if(sqrt(N) == (int)sqrt(N)){
        		N = sqrt(N);
        		answer++;
        	} else{
				// 핵심 알고리즘(단순히 N+1을 하면서 증가할 경우 연산회수가 N의 크기에 비례하여 기하급수적으로 증가함)
        		answer = answer + pow((int)sqrt(N) + 1, 2) - N;
        		N = pow((int)sqrt(N) + 1, 2);
        	}
        }

        cout << '#' << tc << ' ' << answer << endl;
    }

    return 0;
}