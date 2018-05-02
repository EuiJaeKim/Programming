#include <stdio.h>

long long Map[101] = { 0,1,1,1,2,2,3,4,5,7,9, 0, };
long long Init(int Input);

int main()
{
	int TC;
	int Input;

	scanf("%d", &TC);

	for (int i = 11; i <= 100; i++)
		Map[i] = Init(i);

	for (int i = 1; i <= TC; i++) {
		scanf("%d", &Input);
		printf("#%d %lld\n", i, Map[Input]);
	}

	return 0;
}

long long Init(int Input)
{
	if (Input > 0 && Input <= 10)
		return Map[Input];
	else
		return Map[Input - 1] + Map[Input - 5];
}