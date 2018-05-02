#include <cstdio>

int Arr[4];

void Solve();

int main()
{
	int TC;
	int N;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		for (int j = 0; j < 4; j++)
			scanf("%d", &Arr[j]);
		Solve();

		printf("#%d %d %d\n", i, Arr[0], Arr[1]);
	}

	return 0;
}

void Solve()
{
	Arr[1] += Arr[3];
	Arr[0] += Arr[2];
	if (Arr[1] > 60) {
		Arr[0]++;
		Arr[1] -= 60;
	}
	if (Arr[0] > 12)
		Arr[0] -= 12;
}