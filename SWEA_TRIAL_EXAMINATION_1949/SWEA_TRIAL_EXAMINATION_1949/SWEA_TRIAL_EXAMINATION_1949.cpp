#include <cstdio>
#include <cstdlib>

int** Map;
int** Visit;

int N, K;

int Solve(int X, int Y, int Len, int Check);
int RangeCheck(int Temp);

int main()
{
	int T;
	int i, j, k, Max, Fin, FinTemp;
	int MaxArr[100];

	scanf("%d", &T);

	for (i = 1; i <= T; i++)
	{
		scanf("%d %d", &N, &K);
		Max = 0;
		Fin = 0;
		Map = (int**)malloc(sizeof(int*)*N);
		Visit = (int**)malloc(sizeof(int*)*N);
		for (j = 0; j < N; j++) {
			Map[j] = (int*)malloc(sizeof(int)*N);
			Visit[j] = (int*)malloc(sizeof(int)*N);

			for (k = 0; k < N; k++)
			{
				Visit[j][k] = 0;
				scanf("%d", &Map[j][k]);
				if (Max < Map[j][k]) // 최대값 셋팅
					Max = Map[j][k];
			}
		}

		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++)
			{
				if (Map[j][k] == Max) {
					Visit[j][k] = 1;
					FinTemp = Solve(j, k, 1, 0);
					if (FinTemp > Fin)
						Fin = FinTemp;
					Visit[j][k] = 0;
				}
			}
		}

		free(Map);
		printf("#%d %d\n", i, Fin);
	}


	return 0;
}

int Solve(int X, int Y, int Len, int Check)
{
	int Temp, LenTemp, Best;
	Best = Len;
	//위로
	if (RangeCheck(X - 1) && Map[X - 1][Y] < Map[X][Y] && Visit[X - 1][Y] == 0) {
		Visit[X - 1][Y] = 1;
		LenTemp = Solve(X - 1, Y, Len + 1, Check);
		if (Best < LenTemp)
			Best = LenTemp;
		Visit[X - 1][Y] = 0;
	}
	else if (RangeCheck(X - 1) && Check == 0 && Map[X - 1][Y] - K < Map[X][Y] && Visit[X - 1][Y] == 0) {
		Visit[X - 1][Y] = 1;
		Temp = Map[X - 1][Y];
		Map[X - 1][Y] = Map[X][Y] - 1;
		LenTemp = Solve(X - 1, Y, Len + 1, 1);
		if (Best < LenTemp)
			Best = LenTemp;
		Visit[X - 1][Y] = 0;
		Map[X - 1][Y] = Temp;
	}
	//오른쪽
	if (RangeCheck(Y + 1) && Map[X][Y + 1] < Map[X][Y] && Visit[X][Y + 1] == 0) {
		Visit[X][Y + 1] = 1;
		LenTemp = Solve(X, Y + 1, Len + 1, Check);
		if (Best < LenTemp)
			Best = LenTemp;
		Visit[X][Y + 1] = 0;
	}
	else if (RangeCheck(Y + 1) && Check == 0 && Map[X][Y + 1] - K < Map[X][Y] && Visit[X][Y + 1] == 0) {
		Visit[X][Y + 1] = 1;
		Temp = Map[X][Y + 1];
		Map[X][Y + 1] = Map[X][Y] - 1;
		LenTemp = Solve(X, Y + 1, Len + 1, 1);
		if (Best < LenTemp)
			Best = LenTemp;
		Visit[X][Y + 1] = 0;
		Map[X][Y + 1] = Temp;
	}

	//왼쪽
	if (RangeCheck(Y - 1) && Map[X][Y - 1] < Map[X][Y] && Visit[X][Y - 1] == 0) {
		Visit[X][Y - 1] = 1;
		LenTemp = Solve(X, Y - 1, Len + 1, Check);
		if (Best < LenTemp)
			Best = LenTemp;
		Visit[X][Y - 1] = 0;
	}
	else if (RangeCheck(Y - 1) && Check == 0 && Map[X][Y - 1] - K < Map[X][Y] && Visit[X][Y - 1] == 0) {
		Visit[X][Y - 1] = 1;
		Temp = Map[X][Y - 1];
		Map[X][Y - 1] = Map[X][Y] - 1;
		LenTemp = Solve(X, Y - 1, Len + 1, 1);
		if (Best < LenTemp)
			Best = LenTemp;
		Visit[X][Y - 1] = 0;
		Map[X][Y - 1] = Temp;
	}
	//아래
	if (RangeCheck(X + 1) && Map[X + 1][Y] < Map[X][Y] && Visit[X + 1][Y] == 0) {
		Visit[X + 1][Y] = 1;
		LenTemp = Solve(X + 1, Y, Len + 1, Check);
		if (Best < LenTemp)
			Best = LenTemp;
		Visit[X + 1][Y] = 0;
	}
	else if (RangeCheck(X + 1) && Check == 0 && Map[X + 1][Y] - K < Map[X][Y] && Visit[X + 1][Y] == 0) {
		Visit[X + 1][Y] = 1;
		Temp = Map[X + 1][Y];
		Map[X + 1][Y] = Map[X][Y] - 1;
		LenTemp = Solve(X + 1, Y, Len + 1, 1);
		if (Best < LenTemp)
			Best = LenTemp;
		Visit[X + 1][Y] = 0;
		Map[X + 1][Y] = Temp;
	}

	return Best;
}

int RangeCheck(int Temp)
{
	if (Temp >= 0 && Temp < N)
		return 1;
	else
		return 0;
}