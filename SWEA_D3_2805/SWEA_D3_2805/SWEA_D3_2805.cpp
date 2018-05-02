#include <cstdio>

int Map[50][50] = { 0 };
char Temp[50];
int Count;
int N;
void Solve();

int main()
{
	int T;

	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%s", &Temp);
			for (int k = N - 1; k >= 0; k--) {
				Map[j][k] = Temp[k] - '0';
			}
		}

		Solve();
		printf("#%d %d\n", i, Count);
		Count = 0;
	}


	return 0;
}

void Solve()
{
	int x = N / 2;
	int CountTemp = 0;

	for (int j = 0; j <= N / 2; j++) {// Y줄 N/2 까지 가면서
		for (int i = 0; i <= CountTemp; i++) {// X줄 센터부터 위아래로 더하기
			if (x + i != x - i) {
				Count += Map[x + i][j];
				Count += Map[x - i][j];
				if (j != N - j - 1) {
					Count += Map[x + i][N - j - 1];
					Count += Map[x - i][N - j - 1];
				}

			}
			else {
				Count += Map[x + i][j];
				if (j != N - j - 1)
					Count += Map[x - i][N - j - 1];
			}

		}
		CountTemp++;
	}
}