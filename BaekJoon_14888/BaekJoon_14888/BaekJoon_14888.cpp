#include <iostream>
#include <algorithm>

using namespace std;

int N;
long Digit[11] = { 0, };
int Oper[10] = { 0, };
bool OperSel[10];
long Max;
long Min;

void init();
void Solve(int Cnt, long Result);

int main()
{
	init();
	Solve(0, Digit[0]);

	printf("%ld\n%ld",Max,Min);
	return 0;
}

void init()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Digit[i];
	int Temp;
	int OperCnt = 0;
	for (int i = 0; i < 4; i++) {
		cin >> Temp;
		for (int j = 0; j < Temp; j++) {
			Oper[OperCnt++] = i;
		}
	}
	for (int i = 0; i < 10; i++)
		OperSel[i] = false;
	Max = -1987654321;
	Min = 1987654321;
}

void Solve(int Cnt, long Result)
{
	if (Cnt == N-1) {
		if (Min > Result)
			Min = Result;
		if (Max < Result)
			Max = Result;
	}
	else {
		for (int i = 0; i < N-1; i++) {
			if (!OperSel[i]) {
				OperSel[i] = true;
				switch (Oper[i])
				{
				case 0:
					Solve(Cnt + 1, Result + Digit[Cnt + 1]);
					break;
				case 1:
					Solve(Cnt + 1, Result - Digit[Cnt + 1]);
					break;
				case 2:
					Solve(Cnt + 1, Result * Digit[Cnt + 1]);
					break;
				case 3:
					Solve(Cnt + 1, Result / Digit[Cnt + 1]);
					break;
				}
				OperSel[i] = false;
			}
		}
	}
}