#include <stdio.h>
#include <math.h>
#define MAX 16
int Map[MAX][MAX];
int Min;
int N;
void Input();

int Visit[MAX];
void dfs(int Cnt, int VisitCnt);

int main()
{
	int TC;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++)
	{
		scanf("%d", &N);
		Input();
		Min = 5000000;
		dfs(0, 0);
		printf("#%d %d\n", i, Min);
	}
	return 0;
}

void Input()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &Map[i][j]);
	for (int i = 0; i < MAX; i++)
		Visit[i] = 0;
}

void dfs(int Cnt, int VisitCnt)
{
	if (VisitCnt == N / 2) {
		int A[MAX] = { 0, };
		int B[MAX] = { 0, };
		int Ai, Bi;
		Ai = Bi = 0;
		for (int i = 0; i < N; i++)
			if (Visit[i] == 1)
				A[Ai++] = i;
			else
				B[Bi++] = i;
		Ai = Bi = 0;

		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				if (i != j) {
					Ai += Map[A[i]][A[j]];
					Bi += Map[B[i]][B[j]];
				}
			}
		}

		if (Min > abs(Ai - Bi))
			Min = abs(Ai - Bi);
		return;
	}

	if ((N - Cnt) + VisitCnt < N / 2)
		return;

	for (int i = Cnt; i < N && (N - i) + VisitCnt >= N / 2; i++) {
		Visit[i] = 1;
		dfs(i + 1, VisitCnt + 1);
		Visit[i] = 0;
	}
}