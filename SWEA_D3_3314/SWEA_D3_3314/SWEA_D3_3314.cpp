#include <stdio.h>

int main()
{
	int TC;
	int Input;
	int Result;
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		Result = 0;
		for (int j = 0; j < 5; j++) {
			scanf("%d", &Input);
			if (Input < 40)
				Result += 40;
			else
				Result += Input;
		}
		printf("#%d %d\n", i, Result / 5);
	}

	return 0;
}