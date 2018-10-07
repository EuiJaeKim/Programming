#include <stdio.h>
#include <math.h>

#define MAX 16
int Map[MAX][MAX];
int Visit[MAX] = { 1,0, };
int A[8] , B[8];
int Ai, Bi;
int Min;
int N;


void Input();
void Solve(int Cnt, int VisitCnt);

int main()
{
	int TC;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++)
	{
		Input();
		Solve(1, 1);
		printf("#%d %d\n", i, Min);
	}
	return 0;
}

void Input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &Map[i][j]);
	Min = 987654321;
}

void Solve(int Cnt, int VisitCnt)
{
	if (Cnt < N / 2) {
		for (int i = VisitCnt; i < N; i++) {
			Visit[i] = 1;
			Solve(Cnt + 1, i + 1);
			Visit[i] = 0;
			if (Min == 0)
				return;
		}
	}
	else {
		Ai = Bi = 0;
		for (int i = 0; i < N; i++)
			if (Visit[i] == 1)
				A[Ai++] = i;
			else
				B[Bi++] = i;
		Ai = Bi = 0;

		for (int i = 0; i < (N / 2) - 1; i++) {
			for (int j = (N / 2) - 1; j > i; j--) {
				Ai += Map[A[i]][A[j]] + Map[A[j]][A[i]];
				Bi += Map[B[i]][B[j]] + Map[B[j]][B[i]];
			}
		}
		if (Min > abs(Ai - Bi))
			Min = abs(Ai - Bi);
	}
}