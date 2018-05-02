#include <stdio.h>

int main()
{
	int TC;
	long long L, U, X, Result;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%lld", &L);
		scanf("%lld", &U);
		scanf("%lld", &X);

		if (X >= L && X <= U)
			Result = 0;
		else
			if (X > U)
				Result = -1;
			else
				Result = L - X;

		printf("#%d %lld\n", i, Result);
	}
	return 0;
}
