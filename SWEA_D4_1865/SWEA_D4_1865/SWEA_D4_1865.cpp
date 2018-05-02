#include <stdio.h>
#define MAX 16

double Map[MAX][MAX] = { 0, };
int Used[MAX] = { 0, };

double Result;

void Input(int Len);
void Solve(int Cur, double Val, int Len);

int main()
{
	int TC;
	int Length;

	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {

		scanf("%d", &Length);
		Result = 0.0;
		Input(Length);
		Solve(0, 1.0, Length);

		printf("#%d %.6lf\n", i, Result*100.0);
	}

	return 0;
}

void Input(int Len)
{
	int Temp;
	for (int i = 0; i < Len; i++) {
		for (int j = 0; j < Len; j++) {
			scanf("%d", &Temp);
			Map[i][j] = (double)Temp / 100.0;
		}
	}
}

void Solve(int Cur, double Val, int Len)
{
	if (Cur == Len) {
		if (Val > Result)
			Result = Val;
		return;
	}

	for (int i = 0; i < Len; i++) {

		if (Used[i] == 1)
			continue;

		Used[i] = 1;
		if (Val*Map[Cur][i] > Result)
			Solve(Cur + 1, Val*Map[Cur][i], Len);
		Used[i] = 0;
	}
}