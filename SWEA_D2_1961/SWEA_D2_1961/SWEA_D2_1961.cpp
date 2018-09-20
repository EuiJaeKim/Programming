#include <iostream>

using namespace std;

/*

[제약 사항]

N은 3 이상 7 이하이다.

[입력]

가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에 N이 주어지고,

다음 N 줄에는 N x N 행렬이 주어진다.

[출력]

출력의 첫 줄은 '#t'로 시작하고,

다음 N줄에 걸쳐서 90도, 180도, 270도 회전한 모양을 출력한다.

입력과는 달리 출력에서는 회전한 모양 사이에만 공백이 존재함에 유의하라.

*/

int N;
char Map[7][7];

void Solve();

int main()
{
	int TC, Input;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		cin >> N;
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++) {
				cin >> Input;
				Map[j][k] = Input + '0';
			}
		printf("#%d\n", i);
		Solve();
	}

	return 0;
}

void Solve()
{
	for (int i = 0; i < N; i++) {

		for (int k = N - 1; k >= 0; k--) {
			cout << Map[k][i];
		}
		cout << " ";
		for (int k = N - 1; k >= 0; k--) {
			cout << Map[N - i - 1][k];
		}
		cout << " ";
		for (int k = 0; k < N; k++) {
			cout << Map[k][N - i - 1];
		}
		cout << endl;
	}
}