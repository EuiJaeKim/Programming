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

	for (int i = K - 1; i > 0; i--) { // 1줄부터 바꿔볼꺼야 최대 D개의 줄을 바꿀꺼야 근데 ? 그럴필요가 없지 최대 K개만 바꾸면 되니까 
		for (int j = 0; (j + i) <= D; j++) { // j는 시작 Layer
			if (Medicine(i, j))
				return i;
		}
	}
	return K;
}

int Medicine(int Count, int Layer)
{
	int Temp[20];
	int Tem;

	if (Count > 1) { // 2이상이면
		for (int j = 0; j < W; j++) {// 일단 요층 A형으로 바꿔
			Temp[j] = Map[Layer][j];
			Map[Layer][j] = 0;
		}

		for (int j = Layer + 1; j + Count - 1 <= D; j++) {
			Tem = Medicine(Count - 1, j); //내려가~
			if (Tem)// 밑에서 성공했어!?
				return 1;
		}
		// 실패해써.. B형으로 다시해보자아..
		for (int j = 0; j < W; j++)
			Map[Layer][j] = 1;

		for (int j = Layer + 1; j + Count - 1 <= D; j++) {
			Tem = Medicine(Count - 1, j); //내려가~
			if (Tem)// 밑에서 성공했어!?
				return 1;
		}

		//여긴아닌가봐.. 다른곳으로 가봐..
		for (int j = 0; j < W; j++) {
			Map[Layer][j] = Temp[j];
		}
		return 0;
	}
	else { // count = 1
		for (int j = 0; j < W; j++) { // 먼저 A형
			Temp[j] = Map[Layer][j];
			Map[Layer][j] = 0;
		}

		if (Check())// 검사했는데 통과면 끝
			return 1;

		// 아니면 B형 넣어
		for (int j = 0; j < W; j++) {
			Map[Layer][j] = 1;
		}

		if (Check()) // 검사해
			return 1;

		for (int j = 0; j < W; j++) {
			Map[Layer][j] = Temp[j];
		}

		return 0;
	}
}

int Check()
{
	int Temp, TempCount, Flag;
	Flag = 0;

	for (int i = 0; i < W; i++) {
		Temp = Map[0][i];
		TempCount = 1;
		for (int j = 1; j < D; j++) {

			if (Temp == Map[j][i])
				TempCount++;
			else {
				Temp = Map[j][i];
				TempCount = 1;
			}

			if (TempCount == K) {
				Flag++;
				break;
			}
		}
	}
	if (Flag == W)
		return 1;
	else
		return 0;
}