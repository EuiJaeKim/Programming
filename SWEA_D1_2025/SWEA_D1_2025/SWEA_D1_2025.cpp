#include <cstdio>

int main()
{
	int TC;
	unsigned long Result = 0;
	scanf("%d", &TC);
	for (int i = 0; i <= TC; i++)
		Result += i;
	printf("%d", Result);
	return 0;
}