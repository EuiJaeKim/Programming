#include <cstdio>
int Average;
int Solve();

int main()
{
	int TC, Temp;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		Average = 0;
		for (int j = 0; j<10; j++) {
			scanf("%d", &Temp);
			Average += Temp;
		}
		printf("#%d %d\n", i, Solve());
	}
	return 0;
}

int Solve()
{
	if (Average % 10 == 0 || Average % 10 <5)
		return Average / 10;
	else
		return (Average / 10) + 1;
}