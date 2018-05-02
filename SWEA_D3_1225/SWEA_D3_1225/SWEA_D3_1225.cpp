#include <cstdio>
int Map[8] = { 0 };

void Solve();

int main()
{
	int TC;

	for (int i = 1; i <= 10; i++) {
		scanf("%d", &TC);
		for (int j = 0; j < 8; j++) {
			scanf("%d", &Map[j]);
		}

		Solve();
		printf("#%d %d %d %d %d %d %d %d %d\n", TC, Map[0], Map[1], Map[2], Map[3], Map[4], Map[5], Map[6], Map[7]);
	}

	return 0;
}

void Solve()
{
	int Flag;
	int Sub;
	int Temp;
	Flag = 0;
	Sub = 1;
	while (1) {
		for (int i = 0; i < 8; i++) {
			Map[i] -= Sub++;
			if (Map[i] <= 0) {
				Map[i] = 0;
				Flag = 1;
				break;
			}
			if (Sub == 6)
				Sub = 1;
		}
		if (Flag == 1)
			break;
	}

	while (1) {
		Temp = Map[0];
		for (int j = 0; j < 7; j++) {
			Map[j] = Map[j + 1];
		}
		Map[7] = Temp;
		if (Map[7] == 0)
			break;
	}
}