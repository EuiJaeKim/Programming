#include <iostream>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

/*
입력
입력의 첫 줄에는 테스트 케이스의 수 C(C <= 50)가 주어집니다. 각 테스트 케이스의 첫 줄에는 삼각형의 크기 n(2 <= n <= 100)이 주어지고, 그 후 n줄에는 각 1개~n개의 숫자로 삼각형 각 가로줄에 있는 숫자가 왼쪽부터 주어집니다. 각 숫자는 1 이상 100000 이하의 자연수입니다.

출력
각 테스트 케이스마다 한 줄에 최대 경로의 수를 출력합니다.
경로의 수는 2^30 이하라고 가정해도 좋습니다.
*/

int Map[100][100] = { 0, };
int Cache[100][100];
int PathCache[100][100];
int N; /* 2 <= n <= 100 */

void Init();
int Solve(int X, int Y); /* 가장 큰값을 찾으면서 Cache[X][Y] 값 셋팅  */
int PathCount(int X, int Y);

int main()
{
	int TC;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		Init();
		Solve(0, 0);
		cout << PathCount(0, 0) << endl;
	}
	return 0;
}

void Init()
{
	memset(Cache, 0, sizeof(Cache));
	memset(PathCache, 0, sizeof(Cache));
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> Map[i][j];
}

int Solve(int X, int Y)
{
	int& CurSum = Cache[X][Y];

	if (X == N - 1) {
		/* base case 맨 밑층 도착 */
		if (CurSum == 0)
			CurSum = Map[X][Y];
	}
	else {
		/* 가야할 길이 남음 */
		int& LSum = Cache[X + 1][Y];
		int& RSum = Cache[X + 1][Y + 1];

		if (LSum == 0)
			Solve(X + 1, Y);
		if (RSum == 0)
			Solve(X + 1, Y + 1);

		if (LSum > RSum)
			CurSum = Map[X][Y] + LSum;
		else
			CurSum = Map[X][Y] + RSum;
	}

	return CurSum;
}

int PathCount(int X, int Y)
{
	int& Count = PathCache[X][Y];

	/* 맨 마지막 층 */
	if (X == N - 1) 
		Count = 1;

	/* 맨 마지막 층은 아닌데 방문하지 않았어 */
	if (Count == 0) {
		if (Cache[X + 1][Y] > Cache[X + 1][Y + 1])
			Count = PathCount(X + 1, Y);
		else if (Cache[X + 1][Y] < Cache[X + 1][Y + 1])
			Count = PathCount(X + 1, Y + 1);
		else
			Count = PathCount(X + 1, Y) + PathCount(X + 1, Y + 1);
	}

	return Count;
}