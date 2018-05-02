#include <cstdio>

int main()
{
	int TC;
	long long A, B;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d", &A);
		scanf("%d", &B);

		printf("#%d %lld\n", i, (A*A) / (B*B));
	}

	return 0;
}
