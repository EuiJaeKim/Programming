#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int Map[10000] = { 0 };
int InputCount;
char Input[40000];

int compare(const void *first, const void *second);
int Solve();
void Print();
int main()
{
	int TC;
	int i;
	char *Temp, *Count;
	gets
	gets(Input);
	TC = atoi(Input);

	for (i = 1; i <= TC; i++) {
		gets(Input);
		Temp = strtok(Input, " ");
		Count = strtok(NULL, " ");
		InputCount = atoi(Count);
		printf("%s\n", Temp);
		Solve();
		Print();
	}

	return 0;
}

int Solve()
{
	char *Temp;

	gets(Input);
	Temp = strtok(Input, " ");

	for (int i = 1; i <= InputCount; i++) { //3 °³ÀÏ¶§
		if (strcmp("ZRO", Temp) == 0)
			Map[i - 1] = 0;
		else if (strcmp("ONE", Temp) == 0)
			Map[i - 1] = 1;
		else if (strcmp("TWO", Temp) == 0)
			Map[i - 1] = 2;
		else if (strcmp("THR", Temp) == 0)
			Map[i - 1] = 3;
		else if (strcmp("FOR", Temp) == 0)
			Map[i - 1] = 4;
		else if (strcmp("FIV", Temp) == 0)
			Map[i - 1] = 5;
		else if (strcmp("SIX", Temp) == 0)
			Map[i - 1] = 6;
		else if (strcmp("SVN", Temp) == 0)
			Map[i - 1] = 7;
		else if (strcmp("EGT", Temp) == 0)
			Map[i - 1] = 8;
		else if (strcmp("NIN", Temp) == 0)
			Map[i - 1] = 9;
		Temp = strtok(NULL, " ");
	}

	std::qsort(Map, InputCount, sizeof(int), compare);
}

int compare(const void *first, const void *second)
{
	return (*(int*)first - *(int*)second);
}

void Print()
{
	for (int i = 0; i < InputCount; i++) {
		if (Map[i] == 0)
			printf("ZRO ");
		else if (Map[i] == 1)
			printf("ONE ");
		else if (Map[i] == 2)
			printf("TWO ");
		else if (Map[i] == 3)
			printf("THR ");
		else if (Map[i] == 4)
			printf("FOR ");
		else if (Map[i] == 5)
			printf("FIV ");
		else if (Map[i] == 6)
			printf("SIX ");
		else if (Map[i] == 7)
			printf("SVN ");
		else if (Map[i] == 8)
			printf("EGT ");
		else if (Map[i] == 9)
			printf("NIN ");
	}
	printf("\n");
}