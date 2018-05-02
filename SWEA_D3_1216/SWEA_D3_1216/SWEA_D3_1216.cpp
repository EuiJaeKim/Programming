#include <cstdio>
#include <cstring>
#define N 100

char Map[N][N];

int Solve();

int main()
{
	int T = 10;
	char Temp[128];
	int Len;
	for (int k = 1; k <= T; k++) {

		scanf("%d", &Len);
		for (int i = 0; i < N; i++) {
			scanf("%s", &Temp);
			for (int j = 0; j < N; j++) {
				Map[i][j] = Temp[j];
			}
		}

		printf("#%d %d\n", k, Solve());

	}


	return 0;
}

int Solve()
{
	int Flag;
	int h;

	Flag = 0;
	for (int k = 50; k > 1; k--) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (j + k <= N && Map[i][j] == Map[i][j + (k - 1)]) { // 가로
					h = 1;
					do {
						if (Map[i][j + h] != Map[i][j + (k - 1) - h]) {
							Flag = 1;
							break;
						}
						h++;
					} while (h < k / 2);

					if (Flag == 0)
						return k;
					else
						Flag = 0;

				}

				if (i + k <= N && Map[i][j] == Map[i + (k - 1)][j]) { // 세로
					h = 1;
					do {
						if (Map[i + h][j] != Map[i + (k - 1) - h][j]) {
							Flag = 1;
							break;
						}
						h++;
					} while (h < k / 2);

					if (Flag == 0)
						return k;
					else
						Flag = 0;
				}
			}
		}

	}

}