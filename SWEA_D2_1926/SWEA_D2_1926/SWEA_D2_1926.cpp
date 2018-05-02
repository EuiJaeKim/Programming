#include <cstdio>
#include <cstring>

int main()
{
	int N, Flag;
	char NC[5];

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		Flag = 0;
		sprintf(NC, "%d", i);
		for (int j = strlen(NC) - 1; j >= 0; j--) {
			if (NC[j] == '3' || NC[j] == '6' || NC[j] == '9') {
				Flag++;
			}
		}
		if (Flag == 0)
			printf("%d", i);
		else
			for (int j = 0; j < Flag; j++)
				printf("-");
		printf(" ");
	}

	return 0;
}