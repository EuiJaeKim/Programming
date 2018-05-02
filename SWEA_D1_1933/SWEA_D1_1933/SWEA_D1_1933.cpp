#include <cstdio>

int main()
{
	int TC;
	int Arr[1000] = { 0 };
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		if (TC%i == 0)
			printf("%d ", i);;
	}
	return 0;
}