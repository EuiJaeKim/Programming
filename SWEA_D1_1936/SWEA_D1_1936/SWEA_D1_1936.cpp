#include <cstdio>

int main()
{
	int InputOne, InputTwo;

	scanf("%d %d", &InputOne, &InputTwo);

	if (InputOne == 1) {
		if (InputTwo == 2)
			printf("B");
		else
			printf("A");
	}
	else if (InputOne == 2) {
		if (InputTwo == 1)
			printf("A");
		else
			printf("B");
	}
	else if (InputOne == 3) {
		if (InputTwo == 1)
			printf("B");
		else
			printf("A");
	}

	return 0;
}