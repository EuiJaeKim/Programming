#include <stdio.h>
#include <string.h>

char Input[3002];
char Deck[4][13];
int Card[4];

void Init();
int Solve();

int main()
{
	int TC;
	int Flag;
	setbuf(stdout, NULL);
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%s", &Input);
		Init();
		Flag = Solve();
		if (Flag)
			printf("#%d %d %d %d %d\n", i, Card[0], Card[1], Card[2], Card[3]);
		else
			printf("#%d ERROR\n", i);
	}

	return 0;
}

void Init()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++)
			Deck[i][j] = 1;
		Card[i] = 13;
	}
}
int Solve()
{
	char S;
	int XY;

	for (int i = 0; i < strlen(Input); i += 3) {
		S = Input[i];
		XY = ((Input[i + 1] - '0') * 10) + (Input[i + 2] - '0');
		switch (S)
		{
		case 'S':
			if (Deck[0][XY - 1] == 0)
				return 0;
			Deck[0][XY - 1]--;
			Card[0]--;
			break;
		case 'D':
			if (Deck[1][XY - 1] == 0)
				return 0;
			Deck[1][XY - 1]--;
			Card[1]--;
			break;
		case 'H':
			if (Deck[2][XY - 1] == 0)
				return 0;
			Deck[2][XY - 1]--;
			Card[2]--;
			break;
		case 'C':
			if (Deck[3][XY - 1] == 0)
				return 0;
			Deck[3][XY - 1]--;
			Card[3]--;
			break;
		default:
			break;
		}
	}
	return 1;
}