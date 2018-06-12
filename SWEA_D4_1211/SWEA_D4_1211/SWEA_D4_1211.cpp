#include <iostream>

using namespace std;

/*
[제약사항]

한 막대에서 출발한 가로선이 다른 막대를 가로질러서 연속하여 이어지는 경우는 없다.

[입력]

각 테스트 케이스의 첫 번째 줄에는 테스트 케이스의 번호가 주어지며, 바로 다음 줄에 테스트 케이스가 주어진다.

총 10개의 테스트 케이스가 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 도착하게 되는 출발점의 x좌표를 출력한다.
*/

#define Max 100
#define MAX(A,B) A > B ? A : B

int Map[Max][Max];
int MaxVal;
int Res;

void Move(int X, int Y, int Start, int Count);

int main()
{
	int Count;
	for (int i = 1; i <= 10; i++) {
		MaxVal = 987654321;
		cin >> Count;
		for (int j = 0; j < Max; j++)
			for (int k = 0; k < Max; k++)
				cin >> Map[j][k];

		for (int j = 0; j < Max; j++) {
			if (Map[0][j] == 1)
				Move(0, j, j, 1);
		}
		printf("#%d %d\n", Count, Res);
	}

	return 0;
}

void Move(int X, int Y, int Start, int Count)
{
	/* Base Case */
	if (X == Max) {
		if (MaxVal == Count)
			Res = Start;
		else if (MaxVal > Count) {
			MaxVal = Count;
			Res = Start;
		}
		return;
	}
	if (MaxVal <= Count)
		return;

	if (Y - 1 >= 0 && Map[X][Y - 1] == 1) {
		while (Y >= 0 && Map[X][Y] == 1) {
			Y--;
			Count++;
		}
		Y++;
		Count--;
	}
	else if (Y + 1 < Max && Map[X][Y + 1] == 1) {
		while (Y < Max && Map[X][Y] == 1) {
			Y++;
			Count++;
		}
		Y--;
		Count--;
	}

	Move(X + 1, Y, Start, Count + 1);

}