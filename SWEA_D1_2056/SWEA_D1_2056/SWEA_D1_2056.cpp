#include <cstdio>

int Solve(char *Input);

int main()
{
	int TC;
	char Input[10];
	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		scanf("%s", &Input);
		if (Solve(Input))
			printf("#%d %c%c%c%c/%c%c/%c%c\n", i, Input[0], Input[1], Input[2], Input[3], Input[4], Input[5], Input[6], Input[7]);
		else
			printf("#%d -1\n", i);
	}
	return 0;
}

int Solve(char *Input)
{
	int Temp;
	if (Input[4] == '0') {
		if (Input[5] == '1' || Input[5] == '3' || Input[5] == '5' || Input[5] == '7' || Input[5] == '8') {
			Temp = (Input[6] - '0') * 10 + (Input[7] - '0');
			if (Temp >= 1 && Temp <= 31)
				return 1;
			else
				return 0;
		}
		else if (Input[5] == '2') {
			Temp = (Input[6] - '0') * 10 + (Input[7] - '0');
			if (Temp >= 1 && Temp <= 28)
				return 1;
			else
				return 0;
		}
		else {
			Temp = (Input[6] - 10) * 10 + (Input[7] - 10);
			if (Temp >= 1 && Temp <= 30)
				return 1;
			else
				return 0;
		}
	}
	else {
		if (Input[5] == '0' || Input[5] == '2') {
			Temp = (Input[6] - '0') * 10 + (Input[7] - '0');
			if (Temp >= 1 && Temp <= 31)
				return 1;
			else
				return 0;
		}
		else {
			Temp = (Input[6] - '0') * 10 + (Input[7] - '0');
			if (Temp >= 1 && Temp <= 30)
				return 1;
			else
				return 0;
		}
	}
}