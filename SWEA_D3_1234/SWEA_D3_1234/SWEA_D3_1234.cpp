#include <cstdio>

char Original[100];
int N;

void Solve();

int main()
{

	for (int i = 1; i <= 10; i++) {
		scanf("%d %s", &N, &Original);
		Solve();
		printf("#%d ", i);

		for (int j = 0; j < N; j++) {
			if (Original[j] != ' ')
				printf("%c", Original[j]);
		}
		printf("\n");
	}

	return 0;
}

void Solve()
{
	char Temp;
	Temp = Original[0];
	for (int i = 1; i < N; i++) {

		if (Temp == Original[i]) {
			Original[i] = ' ';
			Original[i - 1] = ' ';

			int j, k;
			j = i + 1;
			k = i - 2;

			while (j < N && k >= 0) {
				if (Original[k] == ' ' && k >= 0) {
					while (Original[k] == ' ' && k >= 0) {
						k--;
					}
				}

				if (Original[j] == Original[k]) {
					Original[j] = ' ';
					Original[k] = ' ';
				}
				else {
					Temp = Original[j];
					i = j;
					break;
				}
				j++;
				k--;
			}
		}
		else
			Temp = Original[i];
	}
}