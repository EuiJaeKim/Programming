#include <cstdio>
int Map[10][10];
int N;

void Init();
void Solve();
void print();
int main()
{
	int TC;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		Init();
		scanf("%d", &N);
		Solve();
		printf("#%d\n", i);
		print();
	}

	return 0;
}

void Init()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			Map[i][j] = 0;
}

void Solve()
{
	int Count = 0;
	int Val = 1;
	int Dir = 0;
	int x, y;
	x = y = 0;

	while (1) {
		switch (Dir)
		{
		case 1:
			if (Map[x][y] == 0) {
				Map[x][y] = Val++;
				Count++;
			}

			if (x + 1 < N && Map[x + 1][y] == 0)
				x++;
			else {
				Dir = 2;
				Count = N - y;
			}

			break;
		case 0:
			if (Map[x][y] == 0) {
				Map[x][y] = Val++;
				Count++;
			}
			if (y + 1 < N && Map[x][y + 1] == 0)
				y++;
			else {
				Dir = 1;
				Count = x;
			}
			break;
		case 3:
			if (Map[x][y] == 0) {
				Map[x][y] = Val++;
				Count++;
			}

			if (x - 1 >= 0 && Map[x - 1][y] == 0)
				x--;
			else {
				Dir = 0;
				Count = N - y;
			}
			break;
		case 2:
			if (Map[x][y] == 0) {
				Map[x][y] = Val++;
				Count++;
			}

			if (y - 1 >= 0 && Map[x][y - 1] == 0)
				y--;
			else {
				Count = N - x;
				Dir = 3;
			}
			break;
		}

		if (Val > N*N)
			break;
	}
}

void print()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", Map[i][j]);
		printf("\n");
	}
}