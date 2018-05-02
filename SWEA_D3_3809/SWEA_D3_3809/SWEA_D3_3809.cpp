#include <stdio.h>
int N;
int Map[1000] = { 0, };

void Solve();
int Up(int* Tar, int Num);

int main()
{
	int TC;
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
			scanf("%d", &Map[j]);

		printf("#%d ", i);
		Solve();
		printf("\n");
	}

	return 0;
}

void Solve()
{
	int Target[1000] = { 0, };
	int Check, i, j, k;
	int Count;

	Check = 0;
	i = 0;
	j = 0;

	while (Check != -1 && i + j < N && j < N) {

		if (Map[i] == Target[0]) {
			Count = 1;
			for (k = 1; k <= j; k++) {
				if (Map[i + k] == Target[0 + k])
					Count++;
			}
			if (Count == j + 1) {
				j += Up(Target, j);
				i = -1;
			}
		}
		i++;
	}

	if (Check != -1) {
		for (int p = 0; p <= j; p++)
			printf("%d", Target[p]);
	}

}

int Up(int* Tar, int Num)
{
	if (Tar[Num] < 9) {
		Tar[Num]++;
		return 0;
	}
	else {
		Tar[Num] = 0;
		int i = 1;

		while (Num - i >= 0) {
			if (Tar[Num - i] < 9) {
				Tar[Num - i]++;
				return 0;
			}
			else {
				Tar[Num - i] = 0;
			}
			i++;
		}

		if (Num - i < 0) {
			if (Tar[0] == 0) {
				Tar[0] = 1;
				Tar[Num + 1] = 0;
				return 1;
			}
			else {
				Tar[0]++;
				return 0;
			}
		}
	}
	return 0;
}