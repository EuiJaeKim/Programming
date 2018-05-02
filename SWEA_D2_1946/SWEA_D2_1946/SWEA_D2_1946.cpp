#include <cstdio>
char Map[100];

int main()
{
	int TC;
	int N;
	int Count;
	int Cnt;

	char Input;
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d", &N);
		Cnt = 0;

		for (int j = 0; j < N; j++) {
			scanf(" %c %d", &Input, &Count);
			for (int k = 0; k < Count; k++)
				Map[Cnt++] = Input;
		}
		printf("#%d\n", i);
		for (int j = 0; j < Cnt; j++) {
			if (j % 10 == 0 && j != 0)
				printf("\n%c", Map[j]);
			else
				printf("%c", Map[j]);
		}
		printf("\n");
	}

	return 0;
}