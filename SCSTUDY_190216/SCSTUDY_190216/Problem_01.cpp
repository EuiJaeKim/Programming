#include <stdio.h>

unsigned int Max;

void Solve();

int main()
{
	int TC;
	for (int i = 1; i <= 10; i++) {
		//cin >> TC;
		scanf("%d",&TC);
		Solve();
		printf("#%d %u\n", TC, Max);
	}

	return 0;
}

void Solve()
{
	int RowSum[100] = { 0, }, CulSum, Input, RCross, LCross;
	Max = RCross = LCross = 0;

	for (int i = 0; i < 100; i++) {
		CulSum = 0;
		for (int j = 0; j < 100; j++) {
			//cin >> Input;
			scanf("%d", &Input);
			CulSum += Input;
			RowSum[j] += Input;
			if (i == j)
				RCross += Input;
			if (i + j == 99)
				LCross += Input;
		}
		if (Max < CulSum)
			Max = CulSum;
	}

	for (int i = 0; i < 100; i++) {
		if (RowSum[i] > Max)
			Max = RowSum[i];
	}
	if (RCross > LCross)
		LCross = RCross;
	if (Max < LCross)
		Max = LCross;
}