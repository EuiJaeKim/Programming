#include <cstdio>
int Input[199];
int Length;

void SelectSort();

int main()
{
	scanf("%d", &Length);
	for (int i = 0; i <Length; i++)
		scanf("%d", &Input[i]);
	SelectSort();
	printf("%d", Input[Length / 2]);
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