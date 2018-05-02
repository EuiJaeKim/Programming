#include <cstdio>

int main()
{
	int TC, Temp, Sum;

	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		Sum = 0;
		for (int j = 0; j<10; j++) {
			scanf("%d", &Temp);
			if (Temp % 2 != 0)
				Sum += Temp;
		}
		printf("#%d %d\n", i, Sum);
	}
	return 0;
}