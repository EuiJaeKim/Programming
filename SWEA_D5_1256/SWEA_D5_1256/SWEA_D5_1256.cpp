#include <cstdio>
#include <cstring>
#define Max 410
char Array[Max][Max] = { 0 };
char Input[Max] = { 0 };
int Length;

int Solve();

int main()
{
	int TC;
	int k;

	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		scanf("%d", &k);
		scanf("%s", &Input);
		Length = strlen(Input);
		Solve();
		printf("#%d %s\n", i, Array[k - 1]);
		for (int i = 0; i < Max; i++) {
			for (int j = 0; j < Max; j++)
				Array[i][j] = 0;
			Input[i] = 0;
		}
	}

	return 0;
}

int Solve()
{
	int Curr;

	for (int i = 0; i < Length; i++) {
		Curr = 0;
		for (int j = i; j < Length; j++) {
			Array[i][Curr++] = Input[j];
		}
	}

	for (int i = 0; i < Length; i++) {
		for (int j = i + 1; j < Length; j++) {
			char Temp[Max];
			if (strcmp(Array[i], Array[j]) > 0)
			{
				strcpy(Temp, Array[i]);
				strcpy(Array[i], Array[j]);
				strcpy(Array[j], Temp);
			}
		}
	}
	return 0;
}