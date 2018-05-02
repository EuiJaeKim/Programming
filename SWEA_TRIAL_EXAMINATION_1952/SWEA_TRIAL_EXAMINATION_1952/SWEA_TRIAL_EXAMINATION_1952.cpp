#include <cstdio>
#define MIN(a,b,c,d) (a<b?a:b) < (c<d?c:d) ? (a<b?a:b) : (c<d?c:d)

int Pay[4];
int Month[13];
int DP[13];

int main()
{
	int TC;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		for (int j = 0; j < 4; j++)
			scanf("%d", &Pay[j]);
		for (int j = 1; j < 13; j++)
			scanf("%d ", &Month[j]);

		DP[1] = MIN(Pay[0] * Month[1], Pay[1], Pay[2], Pay[3]);
		DP[2] = MIN(DP[1] + (Pay[0] * Month[2]), DP[1] + Pay[1], Pay[2], Pay[3]);
		DP[3] = MIN(DP[2] + (Pay[0] * Month[3]), DP[2] + Pay[1], Pay[2], Pay[3]);

		for (int j = 4; j < 13; j++)
			DP[j] = MIN(DP[j - 1] + (Pay[0] * Month[j]), DP[j - 1] + Pay[1], DP[j - 3] + Pay[2], Pay[3]);

		printf("#%d %d\n", i, DP[12]);
	}

	return 0;
}