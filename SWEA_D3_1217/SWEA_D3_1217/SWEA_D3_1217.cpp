#include <cstdio>
int N;

int Solve(int Input);

int main()
{
	int M;
	int Count;

	for (int T = 1; T <= 10; T++) {
		scanf("%d", &Count);
		scanf("%d %d", &N, &M);

		printf("#%d %d\n", Count, Solve(M));
	}

	return 0;
}

int Solve(int Input)
{
	if (Input == 1)
		return N;
	else
		return N * Solve(Input - 1);
}