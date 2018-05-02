#include <cstdio>
#include <cstdlib>

int Arr[50];
int compare(const void *a, const void *b);

int main()
{
	int TC;
	int N;
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		for (int j = 0; j < 50; j++)
			Arr[j] = 0;

		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			scanf("%d", &Arr[j]);
		qsort(Arr, N, sizeof(int), compare);

		printf("#%d", i);
		for (int j = 0; j < N; j++)
			printf(" %d", Arr[j]);
		printf("\n");
	}

	return 0;
}

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 < num2)
		return -1;

	if (num1 > num2)
		return 1;

	return 0;
}