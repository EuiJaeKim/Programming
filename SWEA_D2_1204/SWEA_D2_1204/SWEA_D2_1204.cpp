#include <cstdio>

int main()
{
	int Num, i, Temp, j, MaxCount, MaxNum;
	int A[101];
	for (j = 0; j < 10; j++) {

		for (i = 0; i < 101; i++)
			A[i] = 0;

		scanf("%d", &Num);
		for (i = 0; i < 1000; i++)
		{
			scanf("%d", &Temp);
			A[Temp]++;
		}
		MaxCount = 0;
		MaxNum = 0;
		for (i = 0; i < 101; i++)
		{
			if (MaxCount <= A[i]) {
				MaxCount = A[i];
				MaxNum = i;
			}
		}
		printf("#%d %d\n", Num, MaxNum);
	}

	return 0;
}