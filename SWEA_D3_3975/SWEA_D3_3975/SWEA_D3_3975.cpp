#include <stdio.h>

int main()
{
	int TC;
	int A, B, C, D;
	double AB, CD;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		scanf("%d %d %d %d", &A, &B, &C, &D);
		AB = (double)B / (double)A;
		CD = (double)D / (double)C;
		if (AB == CD)
			printf("#%d DRAW\n", i);
		else if (AB < CD)
			printf("#%d ALICE\n", i);
		else
			printf("#%d BOB\n", i);
	}

	return 0;
}