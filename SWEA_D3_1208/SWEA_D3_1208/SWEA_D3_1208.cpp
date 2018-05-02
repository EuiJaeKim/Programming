#include <cstdio>

int main()
{
	int i, j, Dump, Temp;

	for (j = 1; j <= 10; j++) {
		int Arr[100];
		int Mx, Mn, MxNum, MnNum;
		Mx = 0;
		Mn = 100;

		scanf("%d", &Dump);
		for (i = 0; i <100; i++) {
			scanf("%d", &Temp);
			Arr[i] = Temp;
		}
		for (i = 0; i <100; i++) {
			if (Mx < Arr[i]) {
				Mx = Arr[i];
				MxNum = i;
			}
			if (Mn > Arr[i]) {
				Mn = Arr[i];
				MnNum = i;
			}
		}
		while (Dump >0)
		{
			Arr[MxNum] = --Mx;
			Arr[MnNum] = ++Mn;
			for (i = 0; i <100; i++) {
				if (Mx < Arr[i]) {
					Mx = Arr[i];
					MxNum = i;
				}
				if (Mn > Arr[i]) {
					Mn = Arr[i];
					MnNum = i;
				}
			}
			Dump--;
		}
		printf("#%d %d\n", j, Arr[MxNum] - Arr[MnNum]);
	}
	return 0;
}