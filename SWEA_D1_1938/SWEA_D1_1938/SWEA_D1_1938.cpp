#include <cstdio>

int main()
{
	int InputOne, InputTwo;

	scanf("%d %d", &InputOne, &InputTwo);
	printf("%d\n%d\n%d\n%d", InputOne + InputTwo, InputOne - InputTwo, InputOne*InputTwo, InputOne / InputTwo);

	return 0;
}