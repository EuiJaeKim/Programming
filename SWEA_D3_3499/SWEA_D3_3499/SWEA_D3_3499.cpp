#include <stdio.h>
char Arr[1000][90];

int main()
{
	int T;
	int Length;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d", &Length);
		for (int j = 0; j < Length; j++)
			scanf("%s", &Arr[j]);

		int a, b;
		a = 0;
		b = Length / 2;
		if (Length % 2 != 0)
			b++;
		printf("#%d", i);
		for (int j = 0; j < Length / 2; j++) {
			printf(" %s ", Arr[a++]);
			printf("%s", Arr[b++]);
		}
		if (Length % 2 != 0)
			printf(" %s", Arr[(Length / 2)]);
		printf("\n");


	}
	return 0;
}