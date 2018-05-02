#include <stdio.h>
#include <stdlib.h>

int N;
int* Arr;
long long Min;

void Init();
int compare(const void *first, const void *second);
void SUM();

int main()
{
	int TC;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d", &N);
		Init();
		qsort(Arr, N, sizeof(int), compare);
		SUM();
		printf("#%d %lld\n", i, Min);
		free(Arr);
	}

	return 0;
}

void Init()
{
	Arr = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
		scanf("%d", &Arr[i]);
	Min = 0;
}

int compare(const void *first, const void *second)
{
	if (*(int*)first < *(int*)second)
		return 1;
	else
		return -1;
}

void SUM()
{
	for (int i = 0; i < N; i += 3) {
		if (i + 3 <= N) {
			Min += Arr[i] + Arr[i + 1];
		}
		else {
			for (i; i < N; i++)
				Min += Arr[i];
			break;
		}
	}
}