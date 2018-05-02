#include <cstdio>
int Map[100][100];
int Visit[100][100];
int N;

void Solve(int StartX, int StartY);
int RangeCheck(int Input);

int main()
{
	int TC;
	char Input[100];
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%s", &Input);
			for (int k = 0; k < N; k++) {
				Map[j][k] = Input[k] - '0';
				Visit[j][k] = 900;
			}
		}
		Visit[0][0] = 0;
		Solve(0, 0);
		printf("#%d %d\n", i, Visit[N - 1][N - 1]);
	}

}

void Solve(int StartX, int StartY)
{
	if (RangeCheck(StartX - 1) && (Visit[StartX][StartY] + Map[StartX - 1][StartY] < Visit[StartX - 1][StartY])) { // 위
		Visit[StartX - 1][StartY] = Visit[StartX][StartY] + Map[StartX - 1][StartY];
		Solve(StartX - 1, StartY);
	}
	if (RangeCheck(StartY + 1) && (Visit[StartX][StartY] + Map[StartX][StartY + 1] < Visit[StartX][StartY + 1])) { // 오른
		Visit[StartX][StartY + 1] = Visit[StartX][StartY] + Map[StartX][StartY + 1];
		Solve(StartX, StartY + 1);
	}
	if (RangeCheck(StartX + 1) && (Visit[StartX][StartY] + Map[StartX + 1][StartY] < Visit[StartX + 1][StartY])) { // 아래
		Visit[StartX + 1][StartY] = Visit[StartX][StartY] + Map[StartX + 1][StartY];
		Solve(StartX + 1, StartY);
	}
	if (RangeCheck(StartY - 1) && (Visit[StartX][StartY] + Map[StartX][StartY - 1] < Visit[StartX][StartY - 1])) { // 왼
		Visit[StartX][StartY - 1] = Visit[StartX][StartY] + Map[StartX][StartY - 1];
		Solve(StartX, StartY - 1);
	}
}

int RangeCheck(int Input)
{
	if (Input >= 0 && Input < N)
		return 1;
	else
		return 0;
}