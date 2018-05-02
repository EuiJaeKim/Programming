#include <cstdio>
int Map[20][20] = { 0 };
int Desert[101] = { 0 };
int N;
int Result;

void Solve();
int RangeCheck(int X, int Y);
void DesertInit();


int main()
{
	int T, i, j, k;
	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%d", &N);

		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				scanf("%d", &Map[j][k]);
			}
		}
		Result = -1;
		Solve();
		printf("#%d %d\n", i, Result);
	}

	return 0;
}

void Solve()
{
	int i, j, x, y, CurI, CurJ, Temp, Flag;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			for (x = 1; x < N; x++) {
				for (y = 1; y < N; y++) {
					if (RangeCheck(i + x, j + x) && RangeCheck(i + y, j - y) && RangeCheck(i + x + y, j) && Result < (x + y) * 2) { // 사각형이 존재하니? 존재하면 둘레가 이전보다 큰거니? 어차피 작으면 중복이고 뭐고 필요없거든.
						DesertInit();
						CurI = i;
						CurJ = j;
						Flag = 0;

						for (Temp = 0; Temp < x; Temp++) {
							CurI++;
							CurJ++;
							if (Desert[Map[CurI][CurJ]] == 0)// 안먹었던거면
								Desert[Map[CurI][CurJ]] = 1; //먹은거로 체크하고
							else {// 먹었던거면 
								Flag = 1;
								break;
							}
						}
						if (Flag == 1)
							continue; // 먹었던거가 있다 딴거해라

						for (Temp = 0; Temp < y; Temp++) {
							CurI++;
							CurJ--;
							if (Desert[Map[CurI][CurJ]] == 0)// 안먹었던거면
								Desert[Map[CurI][CurJ]] = 1; //먹은거로 체크하고
							else {// 먹었던거면 
								Flag = 1;
								break;
							}
						}
						if (Flag == 1)
							continue; // 먹었던거가 있다 딴거해라

						for (Temp = 0; Temp < x; Temp++) {
							CurI--;
							CurJ--;
							if (Desert[Map[CurI][CurJ]] == 0)// 안먹었던거면
								Desert[Map[CurI][CurJ]] = 1; //먹은거로 체크하고
							else {// 먹었던거면 
								Flag = 1;
								break;
							}
						}
						if (Flag == 1)
							continue; // 먹었던거가 있다 딴거해라

						for (Temp = 0; Temp < y; Temp++) {
							CurI--;
							CurJ++;
							if (Desert[Map[CurI][CurJ]] == 0)// 안먹었던거면
								Desert[Map[CurI][CurJ]] = 1; //먹은거로 체크하고
							else {// 먹었던거면 
								Flag = 1;
								break;
							}
						}
						if (Flag == 1)
							continue; // 먹었던거가 있다 딴거해라

						Result = (x + y) * 2;
					}
				}
			}
		}
	}
}

int RangeCheck(int X, int Y)
{
	if (X >= 0 && X < N && Y >= 0 && Y < N)
		return 1;
	else
		return 0;
}

void DesertInit()
{
	for (int i = 0; i < 101; i++)
		Desert[i] = 0;
}