#include <iostream>

using namespace std;

int Map[10][10] = { 0, };
int MaxMap[10][10] = { 0, };
int N;
int M;
int C;

void Init();
int Solve();
int MaxHoneyValue(int Cnt, int X, int Y, int Limit, int Sum);

int main()
{
	int TC;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		Init();
		printf("#%d %d\n", i, Solve());
	}

	return 0;
}

void Init()
{
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N - M; j++) {
			int Temp;
			int SubMax = 0;
			for (int k = M; k > 0; k--) {
				for (int Y = j; Y + k - 1 < j + M; Y++) {
					Temp = MaxHoneyValue(k, i, Y, j + M, 0);
					if (Temp > SubMax)
						SubMax = Temp;
				}
			}
			MaxMap[i][j] = SubMax;
		}
	}
}

int Solve()
{
	int Max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N - M; j++) {
			int First = 0, Second = 0;
			First = MaxMap[i][j];
			int Y = j + M;
			for (int X = i; X < N; X++) {
				for (Y; Y <= N - M; Y++) {
					Second = MaxMap[X][Y];
					if (First + Second > Max)
						Max = First + Second;
				}
				Y = 0;
			}
		}
	}
	return Max;
}

int MaxHoneyValue(int Cnt, int X, int Y, int Limit, int Sum)
{
	int CurVal = Map[X][Y] * Map[X][Y];
	int Cursum = Sum + Map[X][Y];
	if (Cnt == 1) {
		return CurVal;
	}

	if (Cursum <= C) {
		int SubMax = 0;
		int Temp;
		for (int i = Y; i + Cnt - 1 < Limit; i++) {
			if (Cursum + Map[X][i + 1] <= C) {
				Temp = CurVal + MaxHoneyValue(Cnt - 1, X, i + 1, Limit, Cursum);
				if (Temp > SubMax)
					SubMax = Temp;
			}
		}
		return SubMax;
	}

	return 0;
}