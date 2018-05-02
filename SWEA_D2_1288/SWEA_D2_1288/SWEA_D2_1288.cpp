#include <cstdio>

int main()
{
	int TC;
	int N;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d", &N);

		int Map[10] = { 0, };
		int Count = 1;
		int Temp;
		int Result = 0;

		while (1) {
			Temp = N * Count;
			while (Temp) {
				if (Map[Temp % 10] == 0) {
					Result++;
					Map[Temp % 10] = 1;
				}
				Temp /= 10;
			}
			if (Result == 10)
				break;
			Count++;
		}
		printf("#%d %d\n", i, N*Count);
	}

	return 0;
}