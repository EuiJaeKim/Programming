#include <cstdio>

int Map[15][15] = { 0, };
int N, M;

int Solve();
int Sum(int x, int y);

int main()
{
	int T, Cnt = 1;
	int i, j;

	scanf("%d", &T);
	while (T >= Cnt) {
		scanf("%d", &N);
		scanf("%d", &M);

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				scanf("%d", &Map[i][j]);
			}
		}

		printf("#%d %d\n", Cnt, Solve());
		Cnt++;
	}


	return 0;
}

int Solve()
{
	int i, j;
	int Temp;
	int Result = 0;

	for (i = 0; i + M <= N; i++) {
		for (j = 0; j + M <= N; j++) {
			Temp = Sum(i, j);
			if (Temp > Result)
				Result = Temp;
		}
	}

	return Result;
}

int Sum(int x, int y)
{
	int sum = 0;
	int i, j;

	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			sum += Map[x + i][y + j];
		}
	}
	return sum;
}