#include <cstdio>
int Input[10];
int Length = 10;

void SelectSort();

int main()
{
	int TC;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		for (int j = 0; j <Length; j++)
			scanf("%d", &Input[j]);
		SelectSort();
		printf("#%d %d\n", i, Input[9]);
	}
	return 0;
}

void SelectSort()
{
	int Temp;

	for (int i = 0; i< Length; i++) {
		for (int j = i + 1; j<Length; j++) {
			if (Input[i] > Input[j]) {
				Temp = Input[j];
				Input[j] = Input[i];
				Input[i] = Temp;
			}
		}
	}
}