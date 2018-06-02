#include <iostream>
#include <string.h>

using namespace std;

/*
[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫째 줄에 물건의 개수와 가방의 부피인 N K가 주어진다.

다음 N개의 줄에 걸쳐서 i번 물건의 정보를 나타내는 부피  Vi와 가치 Ci가 주어진다.

[출력]

각 테스트 케이스마다 가방에 담을 수 있는 최대 가치를 출력한다.
*/
#define MAX(A,B) A>B ? A : B
int N; /* 물건의 개수 (1≤N≤100) */
int K; /* 가방의 부피 (1≤K≤1000) */
int Max;
int Map[100][2]; /* 0 : 부피 1: 가치 */

void Search(int Count, int Cur, int SumC, int SumV);

int main()
{
	int TC, Temp;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		memset(Map, 0, sizeof(Map));
		Max = 0;
		cin >> N >> K;
		for (int j = 0; j < N; j++)
			cin >> Map[j][0] >> Map[j][1];
		for (int i = 1; i <= N; i++) {
			Temp = Max;
			Search(i, 0, 0, 0);
			if (Temp == Max)
				break;
			else
				Temp = Max;
		}
		printf("#%d %d\n", i, Max);
	}

	return 0;
}

void Search(int Count, int Cur, int SumC, int SumV)
{
	if (Count == 0)
		Max = MAX(SumC, Max);
	else if (SumV + Map[Cur][0] == K) {
		Max = MAX(SumC, Max);
	}
	else if (SumV + Map[Cur][0] < K) {
		for (int i = Cur; i < N - 1; i++) {
			if (SumV + Map[i][0] <= K)
				Search(Count - 1, i + 1, SumC + Map[i][1], SumV + Map[i][0]);
		}
	}
	return;
}