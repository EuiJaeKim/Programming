#include <cstdio>
#include <cmath>
int main()
{
	int TC;
	scanf("%d", &TC);

	for (int i = 0; i <= TC; i++) {
		printf("%lu ", (long)pow((double)2, (double)i));
	}

	return 0;
}