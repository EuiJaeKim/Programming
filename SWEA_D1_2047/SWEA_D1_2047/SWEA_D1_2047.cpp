#include <cstdio>
#include <cstring>

int main()
{
	char Input[100];
	scanf("%s", &Input);
	for (int i = 0; i<strlen(Input); i++) {
		if (Input[i] >= 'a' && Input[i] <= 'z')
			printf("%c", Input[i] - 32);
		else
			printf("%c", Input[i]);
	}

	return 0;
}