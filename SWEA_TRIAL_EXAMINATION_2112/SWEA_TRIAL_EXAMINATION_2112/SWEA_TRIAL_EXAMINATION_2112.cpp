#include <cstdio>
int D, W, K;

int Map[13][20];

int Check();
int Solve();
int Medicine(int Count, int Layer);

int main()
{
	int T;
	int Result;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d %d", &D, &W, &K);

		for (int j = 0; j < D; j++) {
			for (int k = 0; k < W; k++) {
				scanf("%d", &Map[j][k]);
			}
		}
		printf("#%d %d\n", i, Solve());
	}
	return 0;
}

int Solve()
{
	if (Check())// 안바꿔도 통과입니당
		return 0;

	for (int i = 1; i <= K; i++) {
		for (int j = 0; (j + i) <= D; j++) { // j는 시작 Layer
			if (Medicine(i, j))
				return i;
		}
	}
	return K;
}

int Medicine(int Count, int Layer)
{
	int Temp[20], Result;
	if (Count > 1) {
		for (int i = Layer; i + Count - 1 <= D; i++) {
			for (int j = 0; j < W; j++) {
				Temp[j] = Map[Layer][j];
				Map[Layer][j] = 0;
			}
			Result = Medicine(Count - 1, i + 1);
			if (Result)
				return 1;
			for (int j = 0; j < W; j++) {
				Map[Layer][j] = 1;
			}
			Result = Medicine(Count - 1, i + 1);
			if (Result)
				return 1;
			for (int j = 0; j < W; j++) {
				Map[Layer][j] = Temp[j];
			}
		}
	}
	else {
		for (int j = 0; j < W; j++) {
			Temp[j] = Map[Layer][j];
			Map[Layer][j] = 0;
		}
		if (Check())
			return 1;
		for (int j = 0; j < W; j++) {
			Map[Layer][j] = 1;
		}
		if (Check())
			return 1;
		for (int j = 0; j < W; j++) {
			Map[Layer][j] = Temp[j];
		}
	}
	return 0;
}

int Check()
{
	int Temp;
	bool Flag;

	for (int i = 0; i < W; i++) {
		Flag = false;
		Temp = 0;
		for (int k = 0; k < K; k++)
			Temp += Map[k][i];
		for (int j = K; j <= D; j++) {
			if (Temp == K || Temp == 0)
				break;

			if (j == D)
				return 0;
			Temp -= Map[j - K][i];
			Temp += Map[j][i];
		}
	}
	return 1;
}