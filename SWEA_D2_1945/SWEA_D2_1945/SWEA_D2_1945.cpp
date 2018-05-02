#include <cstdio>

int main()
{
	int TC;
	int N;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d", &N);
		int Arr[5] = { 0, };

		while (N != 1) {
			if (N % 2 == 0) {
				N /= 2;
				Arr[0]++;
			}
			else if (N % 3 == 0) {
				N /= 3;
				Arr[1]++;
			}
			else if (N % 5 == 0) {
				N /= 5;
				Arr[2]++;
			}
			else if (N % 7 == 0) {
				N /= 7;
				Arr[3]++;
			}
			else if (N % 11 == 0) {
				N /= 11;
				Arr[4]++;
			}
		}
		printf("#%d %d %d %d %d %d\n", i, Arr[0], Arr[1], Arr[2], Arr[3], Arr[4]);
	}

	return 0;
}