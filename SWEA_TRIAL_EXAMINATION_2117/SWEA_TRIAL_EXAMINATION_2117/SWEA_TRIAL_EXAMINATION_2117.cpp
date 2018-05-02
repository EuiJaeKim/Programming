#include <cstdio>

int Map[20][20] = { 0, };
int N, M;
int Max;
int TempX, TempY, TempK;

void Solve(int K);
int Cal(int x, int y, int k);
int RangeCheck(int a, int b);
int main()
{
	int TC;
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d %d", &N, &M);
		Max = 1;

		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				scanf("%d", &Map[j][k]);

		if (N % 2 != 0) {
			for (int j = 2; j <= N; j++)
				Solve(j);
		}
		else {
			for (int j = 2; j <= N + 1; j++)
				Solve(j);
		}

		printf("#%d %d\n", i, Max);
	}
	return 0;
}

void Solve(int K)
{
	int Count = 0, X, Y, Temp = 0;
	int Cost = K * K + (K - 1) * (K - 1);
	X = Y = N / 2;
	if ((K == N && N % 2 != 0) || (K == N + 1 && N % 2 == 0)) {
		for (int i = 0; K - (i + 1) >= 0; i++) {
			if (i == 0)
				Temp += Cal(X, Y, K - 1);
			else {
				Temp += Cal(X + i, Y, K - (i + 1));
				Temp += Cal(X - i, Y, K - (i + 1));
			}

		}
		if (Temp*M >= Cost && Temp > Max)
			Max = Temp;
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int h = 0; K - (h + 1) >= 0; h++) {
					if (h == 0)
						Temp += Cal(i, j, K - 1);
					else {
						Temp += Cal(i + h, j, K - (h + 1));
						Temp += Cal(i - h, j, K - (h + 1));
					}
				}
				if (Temp*M >= Cost && Temp > Max)
					Max = Temp;
				Temp = 0;
			}
		}
	}
}

int Cal(int x, int y, int k)
{
	int Count = 0;
	if (RangeCheck(x, y) && Map[x][y] == 1)
		Count++;

	if (k > 0) {
		for (int i = k; i >= 1; i--) {
			if (RangeCheck(x, y + i) && Map[x][y + i] == 1)
				Count++;
			if (RangeCheck(x, y - i) && Map[x][y - i] == 1)
				Count++;
		}
	}

	return Count;
}

int RangeCheck(int a, int b)
{
	if (a >= 0 && a < N && b >= 0 && b < N)
		return 1;
	else
		return 0;
}