#include <cstdio>
#include <cstring>

int main()
{
	char Input[10];
	int Temp = 0;

	scanf("%s", &Input);
	for (int i = 0; i < strlen(Input); i++)
		Temp += Input[i] - '0';
	printf("%d", Temp);
	return 0;
}