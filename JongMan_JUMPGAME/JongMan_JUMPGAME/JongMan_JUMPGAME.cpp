#include <iostream>

using namespace std;
/*
입력
입력의 첫 줄에는 테스트 케이스의 수 C(C <= 50)가 주어집니다. 각 테스트 케이스의 첫 줄에는 격자의 크기 n(2 <= n <= 100)이 주어지고, 그 후 n줄에 각 n개의 숫자로 왼쪽 위부터 각 칸에 쓰인 숫자들이 주어집니다. 오른쪽 아래 있는 끝 점 위치에는 0이 주어집니다.

출력
각 테스트 케이스마다 한 줄로, 시작점에서 끝 점으로 도달할 수 있을 경우 "YES"를, 아닐 경우 "NO"를 출력합니다. (따옴표 제외)
*/
int N;
int Map[100][100] = { -1, }; // 0 : 도착점, 1~9 게임중.
bool Visit[100][100] = { false, };

bool InRange(int A) { if (A >= N) return false; else return true; }
bool Solve(int StartX, int StartY);

int main()
{
	int TC;
	cin >> TC;
	//memset(Map, -1, sizeof(Map));
	for (int i = 0; i < TC; i++) {
		//memset(Visit, false, sizeof(Visit));
		cin >> N;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> Map[j][k];
				Visit[j][k] = false;
			}
				
		}


		if (Solve(0, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}

bool Solve(int StartX, int StartY)
{
	int& Cur = Map[StartX][StartY];
	/* Base Case */
	if (Cur == 0)
		return true;
	bool Ret = false;

	Visit[StartX][StartY] = true;
	/* 범위 안에 있으며 이미 갔던 길이 아닌경우 */
	if (InRange(StartX + Cur) && !Visit[StartX + Cur][StartY])
		Ret = Solve(StartX + Cur, StartY);
	if (Ret)
		return Ret;
	/* 범위 안에 있으며 이미 갔던 길이 아닌경우 */
	if (InRange(StartY + Cur) && !Visit[StartX][StartY + Cur])
		Ret = Solve(StartX, StartY + Cur);

	return Ret;
}