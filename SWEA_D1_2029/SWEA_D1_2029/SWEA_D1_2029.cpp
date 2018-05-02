#include <cstdio>

int main()
{
	int TC, A, B;
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d %d", &A, &B);
		printf("#%d %d %d\n", i, A / B, A%B);
	}
	return 0;
}