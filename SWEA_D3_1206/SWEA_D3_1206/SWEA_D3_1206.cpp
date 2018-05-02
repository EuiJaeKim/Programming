#include <cstdio>
int Arr[1000] = { 0, };

int main()
{
	int i, j, T, Temp;

	for (i = 1; i <= 10; i++) {
		scanf("%d", &T);
		int Count;
		Count = 0;

		for (j = 0; j < T; j++) {
			scanf("%d", &Temp);
			Arr[j] = Temp;
		}

		for (j = 2; j < T - 2; j++) {

			if (Arr[j - 2] < Arr[j] && Arr[j - 1] < Arr[j] && Arr[j + 1] < Arr[j] && Arr[j + 2] < Arr[j]) {
				if (Arr[j - 2] >= Arr[j - 1]) {
					if (Arr[j + 1] >= Arr[j + 2]) {
						if (Arr[j - 2] >= Arr[j + 1])
							Count += Arr[j] - Arr[j - 2];
						else
							Count += Arr[j] - Arr[j + 1];
					}
					else {
						if (Arr[j - 2] >= Arr[j + 2])
							Count += Arr[j] - Arr[j - 2];
						else
							Count += Arr[j] - Arr[j + 2];
					}
				}
				else {
					if (Arr[j + 1] >= Arr[j + 2]) {
						if (Arr[j - 1] >= Arr[j + 1])
							Count += Arr[j] - Arr[j - 1];
						else
							Count += Arr[j] - Arr[j + 1];
					}
					else {
						if (Arr[j - 1] >= Arr[j + 2])
							Count += Arr[j] - Arr[j - 1];
						else
							Count += Arr[j] - Arr[j + 2];
					}
				}
			}
		}
		printf("#%d %d\n", i, Count);
	}
	return 0;
}