#include <cstdio>
int Arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	int TC;
	int N;
	int Result;
	int FirMonth, FirDay, SecMonth, SecDay, Cur;
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d %d %d %d", &FirMonth, &FirDay, &SecMonth, &SecDay);
		Result = 0;
		Cur = FirMonth;
		while (Cur <13) {
			if (Cur == FirMonth) {
				if (FirMonth == SecMonth) {
					Result += SecDay - FirDay + 1;
					break;
				}
				else
					Result += Arr[FirMonth] - FirDay + 1;
			}
			else if (Cur == SecMonth) {
				Result += SecDay;
				break;
			}
			else
				Result += Arr[Cur];
			Cur++;
		}
		printf("#%d %d\n", i, Result);
	}

	return 0;
}