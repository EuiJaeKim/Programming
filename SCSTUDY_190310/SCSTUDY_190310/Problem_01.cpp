#include <stdio.h>

int Map[3]; /* (11 ¡Â D ¡Â 14) */ /* (0 ¡Â H ¡Â 23) */ /* (0 ¡Â M ¡Â 59) */

int Solve();

int main()
{
	int TC;
	scanf("%d",&TC);
	for (register int i = 1; i <= TC; i++) {
		scanf("%d %d %d",&Map[0], &Map[1], &Map[2]);
		printf("#%d %d\n", i, Solve());
	}
	return 0;
}

int Solve()
{
	int Res[3] = { 11,11,11 };
	int Ret;
	for (register int i = 0; i < 3; i++)
		Map[i] -= Res[i];
	Ret = ((Map[0] * 24) + Map[1]) * 60 + Map[2];

	return (Ret < 0 ? -1 : Ret);
}