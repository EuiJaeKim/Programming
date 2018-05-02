#include <cstdio>
#include <stdlib.h>
int N = 100;

int main()
{
	int** Arr;
	int i, Num, j, k;

	Arr = (int**)malloc(sizeof(int*)*N);
	for (i = 0; i < 100; i++) {
		Arr[i] = (int*)malloc(sizeof(int)*N);
	}

	scanf("%d", &Num);

	for (i = 1; i <= 10; i++) {
		int C, R, TSum, LSum, RSum, Sum, TSumTemp, SumTemp, Temp;
		C = 0;
		R = 0;
		TSum = 0;
		LSum = 0;
		Sum = 0;
		RSum = 0;
		TSumTemp = 0;
		SumTemp = 0;

		for (j = 0; j < N*N; j++) {
			scanf("%d", &Temp);
			Arr[C][R] = Temp;
			R++;
			SumTemp += Temp;
			if (R - 1 == C) {//대각
				LSum += Temp;
			}
			if (R == 100) {//가로 최대값
				C++;
				R = 0;
				if (Sum <= SumTemp) {
					Sum = SumTemp;
				}
				SumTemp = 0;
			}
		}// LSum, Sum 계산완료

		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				TSumTemp += Arr[k][j];
				if (j + k == 99)
					RSum += Arr[j][k];
			}
			if (TSum <= TSumTemp)
				TSum = TSumTemp;
			TSumTemp = 0;
		}// TSum, RSum

		if (Sum >= LSum) {
			if (TSum >= RSum) {
				if (Sum >= TSum)
					;
				else
					Sum = TSum;
			}
			else {
				if (Sum >= RSum)
					;
				else
					Sum = RSum;
			}
		}
		else {
			if (TSum >= RSum) {
				if (LSum >= TSum)
					Sum = LSum;
				else
					Sum = TSum;
			}
			else {
				if (LSum >= RSum)
					Sum = LSum;
				else
					Sum = RSum;
			}
		}
		printf("#%d %d\n", Num, Sum);
		scanf("%d", &Num);
	}
	return 0;
}