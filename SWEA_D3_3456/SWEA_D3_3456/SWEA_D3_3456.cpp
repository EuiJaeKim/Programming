#include <stdio.h>

int main()
{
	int T;
	int Input[3];
	int Result;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < 3; j++)
			scanf("%d", &Input[j]);

		if (Input[0] == Input[1])
			Result = Input[2];
		else if (Input[0] == Input[2])
			Result = Input[1];
		else
			Result = Input[0];
		printf("#%d %d\n", i, Result);
	}
	return 0;
}