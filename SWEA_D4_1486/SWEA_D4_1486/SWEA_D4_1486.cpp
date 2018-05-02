#include <cstdio>
#include <cmath>
#define MAX 10001
int H[20] = { 0 };
int Use[20] = { 0 };
int Sum;

int N, B;

int Solve(int Start, int Count, int Temp);

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		scanf("%d", &B);
		Sum = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &H[j]);
			Sum += H[j];
			Use[j] = 1;
		}
		int Temp = 0;
		int Tmp;

		for (int j = 0; j < N; j++) {
			Tmp = Solve(j, N, 0);
			if (Temp < Tmp&& Tmp != -1)
				Temp = Tmp;
		}

		if (Temp == 0)
			printf("#%d %d\n", i, Sum - B);
		else
			printf("#%d %d\n", i, Sum - B - Temp);
	}
	return 0;
}

int Solve(int Start, int Count, int Temp)
{
	if (Count > 0) {
		int Tmp = Temp + H[Start], SumTemp, MaxTemp;
		Use[Start] = 0;
		MaxTemp = Tmp;
		if (Sum - B >= Tmp) {
			for (int i = Start + 1; i < N; i++) {
				SumTemp = Solve(i, Count - 1, Tmp);
				if (SumTemp >= MaxTemp && SumTemp <= Sum - B)
					MaxTemp = SumTemp;
			}
			Use[Start] = 1;
			return MaxTemp;
		}
		else {
			Use[Start] = 1;
			return -1;
		}
	}
	else
		return -1;


}