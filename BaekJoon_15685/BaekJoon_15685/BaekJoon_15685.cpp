#include <iostream>

using namespace std;

/*
입력
첫째 줄에 드래곤 커브의 개수 N(1 ≤ N ≤ 20)이 주어진다. 둘째 줄부터 N개의 줄에는 드래곤 커브의 정보가 주어진다. 드래곤 커브의 정보는 네 정수 x, y, d, g로 이루어져 있다. x와 y는 드래곤 커브의 시작 점, d는 시작 방향, g는 세대이다. (0 ≤ x, y ≤ 100, 0 ≤ d ≤ 3, 0 ≤ g ≤ 10)

입력으로 주어지는 드래곤 커브는 격자 밖으로 벗어나지 않는다. 드래곤 커브는 서로 겹칠 수 있다.

방향은 0, 1, 2, 3 중 하나이고, 다음을 의미한다.

0: x좌표가 증가하는 방향 (→)
1: y좌표가 감소하는 방향 (↑)
2: x좌표가 감소하는 방향 (←)
3: y좌표가 증가하는 방향 (↓)
출력
첫째 줄에 크기가 1×1인 정사각형의 네 꼭지점이 모두 드래곤 커브의 일부인 것의 개수를 출력한다.
*/

#define MAX 101

int Map[MAX][MAX] = { 0, }; /* 0 ≤ x, y ≤ 100 */
int GenCout[11] = { 1,1,2,4,8,16,32,64,128,256,512 };
int G; /* 0 ≤ g ≤ 10 */
int Gen[11][512] = { 0, }; // 각 세대 마다 D 값 저장  

void Solve(int CurX, int CurY, int Gen[11][512]);
void Move(int& X, int& Y, int D);
int CalCount();

int main()
{
	int X, Y, D, N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> X >> Y >> D >> G;
		Gen[0][0] = D;
		Map[Y][X] = 1;
		Solve(X, Y, Gen);
	}
	cout << CalCount() << endl;
	return 0;
}

void Solve(int CurX, int CurY, int Gen[11][512])
{
	int CurGen;
	int CurD;
	int K; // n세대는 0번부터 K개까지의 선을 그음.
	/* 1. 0세대 처리 */
	CurD = Gen[0][0];
	Move(CurX, CurY, CurD);

	/* 2. 1세대부터 G세대까지 간다.  */
	for (int i = 1; i <= G; i++) {
		CurGen = i - 1; // 1세대를 그릴려면 0세대를 봐야하고, 2세대를 그릴려면 1세대를 보고 0세대를 봐야하기 때문에 현재 보고자 하는 세대 -1로 시작.
		K = 0;
		do {
			for (int j = GenCout[CurGen] - 1; j >= 0; j--) {
				CurD = Gen[CurGen][j] + 1; // 시계방향 회전.
				if (CurD == 4)// overflow 처리
					CurD = 0;

				Gen[i][K] = CurD; // 대입
				Move(CurX, CurY, CurD);
				K++; // K 증가
			}
			CurGen--;
		} while (CurGen >= 0);
	}
}

void Move(int& X, int& Y, int D)
{
	switch (D)
	{
	case 0: /* → */
		Map[Y][++X] = 1;
		break;
	case 1: /* ↑ */
		Map[--Y][X] = 1;
		break;
	case 2: /* ← */
		Map[Y][--X] = 1;
		break;
	case 3: /* ↓ */
		Map[++Y][X] = 1;
		break;
	}
}

int CalCount()
{
	int Ret = 0;
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			if (Map[i][j] == 1) {
				if (Map[i][j + 1] == 1 && Map[i + 1][j] == 1 && Map[i + 1][j + 1] == 1)
					Ret++;
			}
		}
	}

	return Ret;
}