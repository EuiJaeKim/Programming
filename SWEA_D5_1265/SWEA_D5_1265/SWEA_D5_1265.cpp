#include <cstdio>

int Money;
int Package;
unsigned long long Map[101];
unsigned long long Max;

void Solve();

int main()
{
	int TC;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		scanf("%d %d", &Money, &Package);
		Max = 1;
		for (int j = 0; j < 100; j++)
			Map[j] = 0;
		Solve();
		printf("#%d %llu\n", i, Max);
	}
	return 0;
}

void Solve()
{
	int Temp = Money / Package;
	int Sum = 0;

	if (Money % Package == 0) {
		for (int i = 0; i < Package; i++)
			Map[i] = Temp;
	}
	else {
		for (int i = 0; i < Package; i++) {
			Sum += Temp;
			Map[i] = Temp;
		}
		while (Sum < Money) {
			for (int i = Package - 1; i >= 0; i--) {
				if (Sum < Money) {
					Map[i]++;
					Sum++;
				}
				else
					break;
			}
		}
	}
	for (int i = 0; i < Package; i++)
		Max *= Map[i];
}