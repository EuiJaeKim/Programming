#include <cstdio>
#include <cstdlib>
#include <cstring>

char Input[7];
int MAX;
void Solve(int Count, int Str);
void Max(int Count, char *Temp, int Cur);
void Swap(char *Temp, int A, int B);
void SelectSort();

int main()
{
	int TC, Count, Str;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d %d", &Str, &Count);
		MAX = 0;
		Solve(Count, Str);
		printf("#%d %d\n", i, MAX);
	}

	return 0;
}

void Solve(int Count, int Str)
{
	sprintf(Input, "%d", Str);

	if (strlen(Input) - 1 > Count) {
		Max(Count, Input, 0);
	}
	else {
		SelectSort();
		int Temp;
		for (int i = 0; i < Count - (strlen(Input) - 1); i++) {
			Swap(Input, strlen(Input) - 2, strlen(Input) - 1);
		}
		MAX = atoi(Input);
	}

}

void Max(int Count, char *Temp, int Cur)
{
	if (Count > 0 && Cur < strlen(Temp) - 1) {
		for (int i = Cur; i < strlen(Temp) - 1; i++) {
			for (int j = i + 1; j < strlen(Temp); j++) {
				Swap(Temp, i, j);
				Max(Count - 1, Temp, i);
				Swap(Temp, i, j);
			}
		}
	}
	else if (Count == 0) {
		if (MAX < atoi(Temp))
			MAX = atoi(Temp);
	}
}

void Swap(char *Temp, int A, int B)
{
	char Tmp = Temp[A];
	Temp[A] = Temp[B];
	Temp[B] = Tmp;
}

void SelectSort()
{
	for (int i = 0; i < strlen(Input); i++) {
		for (int j = i + 1; j < strlen(Input); j++) {
			if (Input[i] < Input[j]) {
				Swap(Input, i, j);
			}
		}
	}
}