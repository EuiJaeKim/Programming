#include <iostream>

using namespace std;

int N; // 1 ¡Â N ¡Â 4
int W; // 2 ¡Â W ¡Â 12
int H; // 2 ¡Â H ¡Â 15

int Map[15][12] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int Min;

void Init();
bool IsRange(int X,int Y);
void Solve(int Count, int Input[15][12]);
void Bomb(int X, int Y, int Input[15][12]);
void Clear(int Input[15][12]);
int Cal(int Input[15][12]);

int main()
{
	int TC;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		Init();
		Solve(N, Map);
		printf("#%d %d\n", i, Min);
	}

	return 0;
}

void Init()
{
	cin >> N >> W >> H;
	Min = 2000;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> Map[i][j];
}

bool IsRange(int X, int Y)
{
	if (X >= 0 && X < H && Y >= 0 && Y < W)
		return true;
	return false;
}

void Solve(int Count, int Input[15][12])
{
	int Temp;
	int Board[15][12];

	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++)
			for (int k = 0; k < W; k++)
				Board[j][k] = Input[j][k];

		int h;
		for (h = 0; h < H; h++) {
			if (Board[h][i] > 0)
				break;
		}
		if (h < H) {
			Bomb(h, i, Board);
			Clear(Board);
		}
		if (Count > 1)
			Solve(Count - 1, Board);
		else {
			Temp = Cal(Board);
			if (Temp < Min)
				Min = Temp;
		}
		if (Min == 0)
			return ;
	}
}

void Bomb(int X, int Y, int Input[15][12])
{
	int Range = Input[X][Y];
	int Dx, Dy;
	int Temp;
	Input[X][Y] = 0;
	for (int i = 1; i < Range; i++) {
		for (int j = 0; j < 4; j++) {
			Dx = X + (dx[j] * i);
			Dy = Y + (dy[j] * i);
			if (IsRange(Dx, Dy)) {
				Temp = Input[Dx][Dy];
				if (Temp > 1) {
					Bomb(Dx, Dy, Input);
				}
				else
					Input[Dx][Dy] = 0;
			}
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
						Input[j--][i] = Input[k][i];
						Input[k][i] = 0;
					}
				}
				break;
			}
		}
	}
}

int Cal(int Input[15][12])
{
	int Result = 0;
	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 0; j--) {
			if (Input[j][i] == 0)
				break;
			else
				Result++;
		}
	}

	return Result;
}