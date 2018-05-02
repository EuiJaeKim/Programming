#include <cstdio>
#include <cstdlib>
int** Map;
int N = 100;

int Solve(int StartX, int StartY);
int RangeCheck(int T);

int main()
{
	int i, j, Count, k;

	Map = (int**)malloc(sizeof(int*)*N);
	for (i = 0; i < N; i++) {
		Map[i] = (int*)malloc(sizeof(int)*N);
	}

	scanf("%d", &Count);
	for (k = 0; k < 10; k++) {
		int StartX, StartY;

		for (i = 0; i < 100; i++) {
			for (j = 0; j < 100; j++) {
				scanf("%d", &Map[i][j]);
				if (Map[i][j] == 2) {
					StartX = i;
					StartY = j;
				}
			}
		}
		printf("#%d %d\n", Count, Solve(99, StartY));
		scanf("%d", &Count);
	}

	return 0;
}

int Solve(int StartX, int StartY)
{
	int Start;
	Start = 0;

	while (StartX > 0) {
		if (RangeCheck(StartY - 1) && Map[StartX][StartY - 1] == 1) {//¿ÞÂÊ
			while (RangeCheck(StartY - 1) && Map[StartX][StartY - 1] == 1) {
				StartY--;
			}
		}
		else if (RangeCheck(StartY + 1) && Map[StartX][StartY + 1] == 1) { //¿À¸¥ÂÊ
			while (RangeCheck(StartY + 1) && Map[StartX][StartY + 1] == 1) {
				StartY++;
			}
		}
		StartX--;
	}

	return StartY;
}

int RangeCheck(int T)
{
	if (T >= 0 && T < N)
		return 1;
	else
		return 0;
}