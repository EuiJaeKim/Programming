#include <stdio.h>

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 1; i <= T; i++)
	{
		char Input[20];
		scanf("%s", &Input);
		int Result = 0;

		for (int j = 0; j < 20; j++) {
			if (Input[j] >= '0' && Input[j] <= '9')
				Result += Input[j] - '0';
			else
				break;
		}


		while (Result >= 10) {
			int Temp = 0;
			while (Result != 0) {
				Temp += Result % 10;
				Result /= 10;
			}
			Result = Temp;
		}

		printf("#%d %d\n", i, Result);
	}
	return 0;
}