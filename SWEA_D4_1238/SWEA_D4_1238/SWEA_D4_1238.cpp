#include <cstdio>
#define N 101

int Map[N][N];
int Visit[N];

void Solve(int Start, int Depth);

int main()
{
	int DataLength, Start;
	int From, To;
	int MaxNum, MaxCount;

	for (int TC = 1; TC <= 10; TC++) {

		for (int i = 0; i < N; i++) {
			Visit[i] = 0;
			for (int j = 0; j < N; j++)
				Map[i][j] = -1;
		}

		scanf("%d", &DataLength);
		scanf("%d", &Start);

		for (int i = 0; i < DataLength / 2; i++) {
			scanf("%d", &From);
			scanf("%d", &To);
			for (int j = 0; j < N; j++)
				if (Map[From][j] == -1) {
					Map[From][j] = To;
					break;
				}
		}
		Solve(Start, 1);
		MaxNum = 0;
		MaxCount = 0;
		for (int i = 0; i < N; i++) {
			if (Visit[i] != 0 && Visit[i] >= MaxCount) {
				if (Visit[i] == MaxCount) {
					if (i > MaxNum)
						MaxNum = i;
				}
				else {
					MaxCount = Visit[i];
					MaxNum = i;
				}
			}
		}
		printf("#%d %d\n", TC, MaxNum);
	}

	return 0;
}

void Solve(int Start, int Depth)
{
	Visit[Start] = Depth;
	for (int i = 0; i < N; i++) {
		if (Map[Start][i] != -1 && (Visit[Map[Start][i]] == 0 || Visit[Map[Start][i]] > Depth + 1)) { // 어디론가 갈수 있어!
			Solve(Map[Start][i], Depth + 1);
		}
		else if (Map[Start][i + 1] != -1)
			;
		else
			break;
	}
	return;
}