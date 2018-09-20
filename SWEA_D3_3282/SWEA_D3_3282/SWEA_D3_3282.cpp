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
int Map[100][2]; /* 0 : 부피 1: 가치 */
int Cache[100][1001];

int Search(int Count, int Vol);

int main()
{
	int TC;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		memset(Map, 0, sizeof(Map));
		memset(Cache, -1, sizeof(Cache));
		cin >> N >> K;
		for (int j = 0; j < N; j++)
			cin >> Map[j][0] >> Map[j][1];

		printf("#%d %d\n", i, Search(0,K));
	}

	return 0;
}

int Search(int Count, int Vol)
{
	/* Base Case */
	if (Count == N)
		return 0;

	if (Cache[Count][Vol] != -1)
		return Cache[Count][Vol];

	Cache[Count][Vol] = Search(Count + 1, Vol);

	if (Vol >= Map[Count][0])
		Cache[Count][Vol] = MAX(Cache[Count][Vol], Search(Count + 1, Vol - Map[Count][0]) + Map[Count][1]);

	return Cache[Count][Vol];
}