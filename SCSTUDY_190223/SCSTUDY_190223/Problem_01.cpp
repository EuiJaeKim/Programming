#include <iostream>
#include <cstring>
using namespace std;

#define CardCount 18
#define CardCountHalf 9
#define Half 85
bool Card[CardCount + 1];
int Inyoungs_Card[CardCountHalf], Gyuyoungs_Card[CardCountHalf];
int Lose;
void Init();
void dfs(int Count, int A, int B);

int main()
{
	int TC;
	//cin >> TC;
	scanf("%d", &TC);

	for (register int i = 1; i <= TC; i++) {
		Init();
		dfs(0, 0, 0);
		printf("#%d %d %d\n", i, 362880 - Lose, Lose);
	}

	return 0;
}

void Init()
{
	Lose = 0;
	memset(Card, 0, sizeof(Card));
	for (register int i = 0; i < CardCountHalf; i++) {
		//cin >> Gyuyoungs_Card[i];
		scanf("%d", &Gyuyoungs_Card[i]);
		Card[Gyuyoungs_Card[i]] = true;
	}

	register int Temp = 0;
	for (register int i = 1; i < CardCountHalf; i++) {
		if (!Card[i]) {
			Inyoungs_Card[Temp++] = i;
		}
	}

}

void dfs(int Count, int A, int B)
{
	if (A > Half) {
		return;
	}
	else if (B > Half) {
		register int Temp = 1;
		for (register int i = Count; i < CardCountHalf; i++) {
			Temp *= (CardCountHalf) - i;
		}
		Lose += Temp;
		return;
	}
	else {
		for (register int i = 0; i < CardCountHalf; i++) {
			if (!Card[Inyoungs_Card[i]]) {
				Card[Inyoungs_Card[i]] = true;
				if (Gyuyoungs_Card[Count] > Inyoungs_Card[i])
					dfs(Count + 1, A + Gyuyoungs_Card[Count] + Inyoungs_Card[i], B);
				else
					dfs(Count + 1, A, B + Gyuyoungs_Card[Count] + Inyoungs_Card[i]);
				Card[Inyoungs_Card[i]] = false;
			}
		}
		return;
	}
}