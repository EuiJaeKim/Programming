#include <stdio.h>

int main()
{
	int TC;
	long long Input, A, B;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%lld", &Input);
		A = Input * Input;
		B = A + Input;
		printf("#%d %lld %lld %lld\n", i, Input*(Input + 1) / 2, A, B);
	}
	return 0;
}
