#include <stdio.h>

int Map[20][20];
int MapB[20][20];

int Length;
int X;

void Init();
int Solve();
int SolveB();
void print();

int main()
{

	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d", &Length);
		scanf("%d", &X);

		Init();
		printf("#%d %d\n", i, Solve() + SolveB());

		//print();
	}

	return 0;
}

void print()
{
	for (int i = 0; i < Length; i++) {
		for (int j = 0; j < Length; j++) {
			printf("%d ", Map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < Length; i++) {
		for (int j = 0; j < Length; j++) {
			printf("%d ", MapB[i][j]);
		}
		printf("\n");
	}
}

void Init()
{
	for (int i = 0; i < Length; i++) {
		for (int j = 0; j < Length; j++) {
			scanf("%d", &Map[i][j]);
			MapB[j][i] = Map[i][j];
		}
	}
}

int Solve()
{
	int	Prev = 0;
	int Flag;
	int	Count = 0;

	for (int i = 0; i < Length; i++) {
		Prev = 0;
		Flag = 0;
		for (int j = 0; j < Length; j++) {
			if (Prev == 0)
				Prev = Map[i][j];
			else if (Flag == 0) {
				if (Prev != Map[i][j]) {// 경사로 구축 필요
					if (Prev - 1 == Map[i][j]) {// 4 3 

						if (j + X <= Length) { // 지을 수 있음
							for (int k = 1; k < X && Flag == 0; k++) {
								if (Map[i][j + k] != Map[i][j])
									Flag = 1;
							}

							if (Flag == 0) {// 경사로 짓자
								Prev = Map[i][j + X - 1];
								for (int k = 0; k < X; k++) {
									Map[i][j + k] = 9;
								}
								j += X - 1;
							}
						}
						else { // 없음
							Flag = 1;
						}

					}
					else if (Map[i][j - 1] + 1 == Map[i][j]) { // 3 4
						if (j - X >= 0) { // 지을 수 있음
							for (int k = 2; k <= X && Flag == 0; k++) {
								if (Map[i][j - k] != Map[i][j - 1])
									Flag = 1;
							}

							if (Flag == 0) {// 경사로 짓자
								Prev = Map[i][j];
								for (int k = 1; k <= X; k++) {
									Map[i][j - k] = 9;
								}
							}
						}
						else { // 없음
							Flag = 1;
						}
					}
					else
						Flag = 1;
				}
				else {
					Prev = Map[i][j];
				}

			}
		}
		if (Flag == 0)
			Count++;
	}

	return Count;
}
int SolveB()
{
	int	Prev = 0;
	int Flag;
	int	Count = 0;

	for (int i = 0; i < Length; i++) {
		Prev = 0;
		Flag = 0;
		for (int j = 0; j < Length; j++) {
			if (Prev == 0)
				Prev = MapB[i][j];
			else if (Flag == 0) {
				if (Prev != MapB[i][j]) {// 경사로 구축 필요
					if (Prev - 1 == MapB[i][j]) {// 4 3 

						if (j + X <= Length) { // 지을 수 있음
							for (int k = 1; k < X && Flag == 0; k++) {
								if (MapB[i][j + k] != MapB[i][j])
									Flag = 1;
							}

							if (Flag == 0) {// 경사로 짓자
								Prev = MapB[i][j + X - 1];
								for (int k = 0; k < X; k++) {
									MapB[i][j + k] = 9;
								}
								j += X - 1;
							}
						}
						else { // 없음
							Flag = 1;
						}

					}
					else if (MapB[i][j - 1] + 1 == MapB[i][j]) { // 3 4
						if (j - X >= 0) { // 지을 수 있음
							for (int k = 2; k <= X && Flag == 0; k++) {
								if (MapB[i][j - k] != MapB[i][j - 1])
									Flag = 1;
							}

							if (Flag == 0) {// 경사로 짓자
								Prev = MapB[i][j];
								for (int k = 1; k <= X; k++) {
									MapB[i][j - k] = 9;
								}
							}
						}
						else { // 없음
							Flag = 1;
						}
					}
					else
						Flag = 1;
				}
				else {
					Prev = MapB[i][j];
				}

			}
		}
		if (Flag == 0)
			Count++;
	}

	return Count;
}