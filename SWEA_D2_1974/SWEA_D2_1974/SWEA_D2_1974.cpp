#include <iostream>

using namespace std;

/*

[제약 사항]

1. 퍼즐은 모두 숫자로 채워진 상태로 주어진다.

2. 입력으로 주어지는 퍼즐의 모든 숫자는 1 이상 9 이하의 정수이다.


[입력]

입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.

다음 줄부터 각 테스트 케이스가 주어진다.

테스트 케이스는 9 x 9 크기의 퍼즐의 데이터이다.


[출력]

테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.

*/

#define Length 9

int Map[9][9] = { 0, };

int Solve();

int main()
{
	int TC;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		/* 1. 입력단 */
		for (int j = 0; j < Length; j++)
			for (int k = 0; k < Length; k++)
				cin >> Map[j][k];
		/* 2. 계산하러 가쯔아 */
		printf("#%d %d\n", i, Solve());
	}

	return 0;
}

int Solve()
{
	int Sum;

	/* 3. 가로행 검사 */
	for (int i = 0; i < Length; i++) {
		Sum = 0;
		for (int j = 0; j < Length; j++)
			Sum += Map[i][j];
		if (Sum != 45)
			return 0;
	}
	/* 4. 세로열 검사 */
	for (int i = 0; i < Length; i++) {
		Sum = 0;
		for (int j = 0; j < Length; j++)
			Sum += Map[j][i];
		if (Sum != 45)
			return 0;
	}
	/* 5. 3x3 검사 */

	for (int i = 0; i < 9; i += 3) {
		for (int j = 0; j < 9; j += 3) {
			Sum = 0;
			for (int x = i; x < i + 3; x++) {
				for (int y = j; y < j + 3; y++) {
					Sum += Map[x][y];
				}
			}
			if (Sum != 45)
				return 0;
		}
	}

	return 1;
}