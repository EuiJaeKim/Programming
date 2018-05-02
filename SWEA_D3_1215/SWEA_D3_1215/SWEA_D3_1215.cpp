#include <cstdio>
#include <cstring>
#define N 8

char Map[N][N];
int Len;
int Count;

void Solve();

int main()
{
	int T = 10;
	char Temp[10];

	for (int k = 1; k <= T; k++) {

		scanf("%d", &Len);
		for (int i = 0; i < N; i++) {
			scanf("%s", &Temp);
			for (int j = 0; j < N; j++) {
				Map[i][j] = Temp[j];
			}
		}
		Count = 0;

		Solve();

		printf("#%d %d\n", k, Count);

	}


	return 0;
}

void Solve()
{
	int Flag;
	int k;

	Flag = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j + Len <= N && Map[i][j] == Map[i][j + (Len - 1)]) { // 가로
				k = 1;
				do {
					if (Map[i][j + k] != Map[i][j + (Len - 1) - k]) {
						Flag = 1;
						break;
					}
					k++;
				} while (k < Len / 2);

				if (Flag == 0)
					Count++;
				else
					Flag = 0;
			}

			if (i + Len <= N && Map[i][j] == Map[i + (Len - 1)][j]) { // 세로
				k = 1;
				do {
					if (Map[i + k][j] != Map[i + (Len - 1) - k][j]) {
						Flag = 1;
						break;
					}
					k++;
				} while (k < Len / 2);

				if (Flag == 0)
					Count++;
				else
					Flag = 0;
			}
		}
	}
}