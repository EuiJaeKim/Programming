#include <cstdio>
#define N 100

int Map[N][N];
int Visit[N][N];

int Solve(int StartA, int StartB);

int main()
{
	char Temp[N + 2];
	int TC = 0;
	int StartX, StartY;

	while (TC <10) {
		scanf("%d", &TC);

		for (int i = 0; i < N; i++) {
			scanf("%s", &Temp);
			for (int j = 0; j < N; j++) {
				Map[i][j] = Temp[j] - '0';
				Visit[i][j] = Temp[j] - '0';
				if (Map[i][j] == 2) {
					StartX = i;
					StartY = j;
				}
			}
		}
		printf("#%d %d\n", TC, Solve(StartX, StartY));
	}

	return 0;
}

int Solve(int StartA, int StartB)
{
	if (Map[StartA][StartB] == 3)
		return 1;

	Visit[StartA][StartB] = 1;

	int Temp = 0;

	if (Map[StartA][StartB - 1] != 1 && Visit[StartA][StartB - 1] != 1)
		Temp = Solve(StartA, StartB - 1);

	if (Temp != 1 && Map[StartA + 1][StartB] != 1 && Visit[StartA + 1][StartB] != 1)
		Temp = Solve(StartA + 1, StartB);

	if (Temp != 1 && Map[StartA][StartB + 1] != 1 && Visit[StartA][StartB + 1] != 1)
		Temp = Solve(StartA, StartB + 1);

	if (Temp != 1 && Map[StartA - 1][StartB] != 1 && Visit[StartA - 1][StartB] != 1)
		Temp = Solve(StartA - 1, StartB);

	if (!Temp)
		return Temp;
	else
		return Temp;
}