#include <iostream>
#include <string.h>

using namespace std;

/*
[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 하나의 자연수 N(1 ≤ N ≤ 10)이 주어진다.


[출력]

각 테스트 케이스마다 ‘#x ’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
*/

int N;
int Map[11] = { 0, };
int XArray[11] = { 0, };

void Init();
void dfs(int Max, int Cur);
bool IsPossible(int Max, int Cur, int Val);

int main()
{
	int TC;

	cin >> TC;
	Init();

	for (int i = 1; i <= TC; i++) {
		cin >> N;
		printf("#%d %d\n", i, Map[N]);
	}
}

void Init()
{
	for (int i = 1; i <= 10; i++) {
		memset(XArray,-1, sizeof(XArray));
		dfs(i, 0);
	}
}

void dfs(int Max, int Cur)
{// cur은 위 아래 y축
	if (Max == Cur) {
		Map[Max]++;
		return;
	}

	for (int i = 0; i < Max; i++) { // i는 왼쪽 오른쪽 x축
		if (IsPossible(Max, Cur, i)) {
			XArray[i] = Cur;
			dfs(Max, Cur + 1);
			XArray[i] = -1;
		}
	}
}

bool IsPossible(int Max, int Cur, int Val) // Cur은 y축 Val은 x축
{
	if (XArray[Val] != -1)
		return false;
	for (int i = 1; Cur - i >= 0; i++) {
		if (Val - i >= 0 && XArray[Val - i] == Cur - i)
			return false;
		if (Val + i < Max && XArray[Val + i] == Cur - i)
			return false;
	}
	return true;
}