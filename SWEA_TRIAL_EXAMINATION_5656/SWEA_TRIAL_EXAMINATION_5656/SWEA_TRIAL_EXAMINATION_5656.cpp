#include <iostream>

using namespace std;

int N; // 1 ≤ N ≤ 4
int W; // 2 ≤ W ≤ 12
int H; // 2 ≤ H ≤ 15

int Map[15][12] = { 0, }; // 벽돌은 숫자 1 ~ 9

void Init();
int Solve(int Count, int Input[15][12]);
void Bomb(int X, int Y, int Input[15][12]);
void Clear(int Input[15][12]);
int Cal(int Input[15][12]);

int main()
{
	int TC;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		Init();
		printf("#%d %d\n", i, Solve(N, Map));
	}

	return 0;
}

void Init()
{
	cin >> N >> W >> H;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> Map[i][j];
}

int Solve(int Count, int Input[15][12])
{
	int Min = 987654321;
	int Temp;
	int Board[15][12];

	for (int i = 0; i < W; i++) {
		// 1. 원본 가져오기
		for (int j = 0; j < H; j++)
			for (int k = 0; k < W; k++)
				Board[j][k] = Input[j][k];

		// 2. H 쭉 써치 하면서 제일 위 찾는다.
		int h;
		for (h = 0; h < H; h++) {
			if (Board[h][i] > 0)
				break;
		}
		// 3.1. 발견되면
		if (h < H) {
			Bomb(h, i, Board);
			Clear(Board);
			if (Count > 1) {
				Temp = Solve(Count - 1, Board);
				if (Temp < Min)
					Min = Temp;
			}
		}

		Temp = Cal(Board);
		if (Temp < Min)
			Min = Temp;

		if (Min == 0)
			return Min;
	}
	return Min;
}

void Bomb(int X, int Y, int Input[15][12])
{
	int Range = Input[X][Y];
	int Temp;
	Input[X][Y] = 0;
	for (int i = 1; i < Range; i++) {
		if (X - i >= 0) {
			Temp = Input[X - i][Y];
			if (Temp > 1) {
				Bomb(X - i, Y, Input);
			}
			else
				Input[X - i][Y] = 0;
		}
		if (X + i < H) {
			Temp = Input[X + i][Y];
			if (Temp > 1) {
				Bomb(X + i, Y, Input);
			}
			else
				Input[X + i][Y] = 0;
		}
		if (Y - i >= 0) {
			Temp = Input[X][Y - i];
			if (Temp > 1) {
				Bomb(X, Y - i, Input);
			}
			else
				Input[X][Y - i] = 0;
		}
		if (Y + i < W) {
			Temp = Input[X][Y + i];
			if (Temp > 1) {
				Bomb(X, Y + i, Input);
			}
			else
				Input[X][Y + i] = 0;
		}
	}
}

void Clear(int Input[15][12])
{
	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 0; j--) {
			if (Input[j][i] == 0) {
				for (int k = j - 1; k >= 0; k--) {
					if (Input[k][i] != 0) {
						Input[j][i] = Input[k][i];
						Input[k][i] = 0;
						break;
					}
				}
			}
		}
	}
}

int Cal(int Input[15][12])
{
	int Result = 0;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			if (Input[i][j] > 0)
				Result++;

	return Result;
}