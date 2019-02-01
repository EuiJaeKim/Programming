#include <iostream>

using namespace std;

int Magnet[4][8];
int Top[4];
int K;
int Rotate[20][2];

void Init();
void Solve(int Num, int Dir);
int Search(int Num, int Dir);

int main()
{
	int TC;

	cin >> TC;
	for (int i = 1; i <= TC; i++)
	{
		Init();
		for (int j = 0; j < K; j++)
			Solve(Rotate[j][0], Rotate[j][1]);
		printf("#%d %d\n", i, Magnet[0][Top[0]] * 1 + Magnet[1][Top[1]] * 2 + Magnet[2][Top[2]] * 4 + Magnet[3][Top[3]] * 8);
	}


	return 0;
}

void Init()
{
	cin >> K;

	for (int i = 0; i < 4; i++) {
		Top[i] = 0;
		for (int j = 0; j < 8; j++) {
			cin >> Magnet[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> Rotate[i][0] >> Rotate[i][1];
	}
}

void Solve(int Num, int Dir)
{
	int RotateArr[4] = { 0, };

	RotateArr[Num - 1] = Dir;

	for (int i = Num; i < 4; i++) {
		if (Search(i, 0) != Search(i - 1, 1)) {
			if (RotateArr[i - 1] == 1)
				RotateArr[i] = -1;
			else
				RotateArr[i] = 1;
		}
		else
			break;
	}
	for (int i = Num - 2; i >= 0; i--) {
		if (Search(i, 1) != Search(i + 1, 0)) {
			if (RotateArr[i + 1] == 1)
				RotateArr[i] = -1;
			else
				RotateArr[i] = 1;
		}
		else
			break;
	}

	for (int i = 0; i < 4; i++) {
		if (RotateArr[i] == 1) {
			Top[i]--;
			if (Top[i] < 0) {
				Top[i] += 8;
			}
		}
		else if (RotateArr[i] == -1) {
			Top[i]++;
			if (Top[i] > 7) {
				Top[i] -= 8;
			}
		}
	}

}

int Search(int Num, int Dir)
{
	if (Dir == 1) {
		if (Top[Num] + 2 < 8)
			return Magnet[Num][Top[Num] + 2];
		else
			return Magnet[Num][Top[Num] - 6];
	}
	else {
		if (Top[Num] - 2 > -1)
			return Magnet[Num][Top[Num] - 2];
		else
			return Magnet[Num][Top[Num] + 6];
	}
}