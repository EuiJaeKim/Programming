#include <cstdio>

int Map[100][100] = { 0 };
int Visit[100][100];
int Result[20][3] = { 0 };
int ResultCount;
int N;


void Solve();
void Sort();

int main()
{
	int TC;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d", &N);
		ResultCount = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				scanf("%d", &Map[j][k]);
				Visit[j][k] = 0;
			}
		}
		Solve();
		Sort();
		printf("#%d %d", i, ResultCount);
		for (int j = 0; j < ResultCount; j++)
			printf(" %d %d", Result[j][0], Result[j][1]);

		printf("\n");
	}

	return 0;
}

void Solve()
{
	int TempI, TempJ;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j] != 0 && Visit[i][j] == 0) { // ¹ß°ß
				TempI = i;
				TempJ = j;
				while (TempJ < N && Map[TempI][TempJ] != 0) {
					while (TempI < N && Map[TempI][TempJ] != 0) {
						Visit[TempI][TempJ] = 1;
						TempI++;
					}
					Result[ResultCount][0] = TempI - i;
					TempI = i;
					TempJ++;
				}
				Result[ResultCount][1] = TempJ - j;
				ResultCount++;
			}
		}
	}
}
void Sort()
{
	int min, Temp, Tmp;
	for (int i = 0; i < ResultCount; i++) {
		min = 99999;
		for (int j = i; j < ResultCount; j++) {
			if (min >= Result[j][0] * Result[j][1]) {
				if (min == Result[j][0] * Result[j][1]) {
					if (Result[Temp][0] > Result[j][0])
						Temp = j;
				}
				else {
					Temp = j;
					min = Result[j][0] * Result[j][1];
				}

			}
		}
		Tmp = Result[i][0];
		Result[i][0] = Result[Temp][0];
		Result[Temp][0] = Tmp;
		Tmp = Result[i][1];
		Result[i][1] = Result[Temp][1];
		Result[Temp][1] = Tmp;
	}
}