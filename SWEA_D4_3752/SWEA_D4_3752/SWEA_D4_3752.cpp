#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

int N;
int Map[MAX];
int Visit[MAX];
int Result;

int main()
{
	int TC;
	int Input;
	int Temp;

	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		for (int j = 0; j < MAX; j++) {
			Map[j] = 0;
			Visit[j] = 0;
		}
		scanf("%d", &N);
		Map[0] = 0;
		Result = 1;
		for (int j = 1; j <= N; j++) {
			scanf("%d", &Input);
			Temp = 0;
			for (int k = 0; k < Result; k++) {
				if (Visit[Input + Map[k]] == 0) {
					Visit[Input + Map[k]] = 1;
					Map[Result + (Temp++)] = Input + Map[k];
				}
			}
			Result += Temp;
		}
		printf("#%d %d\n", i, Result);
	}

	return 0;
}