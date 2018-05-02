#include <cstdio>

int Map[15][15];
int N, K;
int Result;
void Init();
void Solve();

int main()
{
	int TC;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d", &N);
		scanf("%d", &K);
		Init();
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				scanf("%d", &Map[j][k]);
		Result = 0;
		Solve();

		printf("#%d %d\n", i, Result);
	}

	return 0;
}

void Init()
{
	for (int j = 0; j < N; j++)
		for (int k = 0; k < N; k++)
			Map[j][k] = 3;
}

void Solve()
{
	int Prev = 0;

	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			if (Map[j][k] == 1) {

				if (Prev == 0 && k + K <= N) {
					int i;
					for (i = 0; i + k < N; i++) {
						if (!Map[j][k + i]) {
							break;
						}
					}
					if (i == K)
						Result++;
				}

				if (((j == 0) || (j - 1 >= 0 && Map[j - 1][k] == 0)) && j + K <= N) {
					int i;
					for (i = 0; i + j < N; i++) {
						if (!Map[j + i][k]) {
							break;
						}
					}
					if (i == K)
						Result++;
				}
			}
			Prev = Map[j][k];
		}
		Prev = 0;
	}
}