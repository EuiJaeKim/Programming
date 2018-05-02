#include <cstdio>
#include <cstring>
int main()
{
	char Input[150];
	scanf("%s", &Input);
	for (int i = 0; i<strlen(Input); i++)
		printf("%d ", Input[i] - 'A' + 1);
	return 0;
}