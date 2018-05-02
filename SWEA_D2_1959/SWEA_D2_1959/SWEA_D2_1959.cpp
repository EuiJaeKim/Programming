#include <cstdio>

int A[20] = { 0, }, B[20] = { 0, };
int N, M;

int Solve();

int main()
{
	int TC;
	int j;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d %d", &N, &M);

		for (j = 0; j < N; j++)
			scanf("%d", &A[j]);

		for (j = 0; j < M; j++)
			scanf("%d", &B[j]);

		printf("#%d %d\n", i, Solve());
	}

	return 0;
}

int Solve()
{
	int Cur;
	int Result = 0;

	if (N > M) {
		for (int i = 0; i + M <= N; i++) {
			Cur = 0;
			for (int j = 0; j < M; j++) {
				Cur += A[i + j] * B[j];
			}
			if (Result < Cur)
				Result = Cur;
		}
	}
	else if (N < M) {
		for (int i = 0; i + N <= M; i++) {
			Cur = 0;
			for (int j = 0; j < N; j++) {
				Cur += B[i + j] * A[j];
			}
			if (Result < Cur)
				Result = Cur;
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			Result += A[i] * B[i];
		}
	}
	return Result;
}