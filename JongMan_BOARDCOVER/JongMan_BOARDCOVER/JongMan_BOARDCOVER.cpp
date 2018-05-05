#include <iostream>
#define InRangeX(x) x < H ? x >= 0 ? true :false :false
#define InRangeY(y) y < W ? y >= 0 ? true :false :false
using namespace std;

char Map[20][20] = { 0, };
int H, W; // H, W (1 <= H,W <= 20) 
int Result;
int DotCount;

void Solve(int CurX, int CurY, int Count);
void FindTarget(int& X, int& Y);

/*
입력
력의 첫 줄에는 테스트 케이스의 수 C (C <= 30) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 2개의 정수 H, W (1 <= H,W <= 20) 가 주어집니다. 다음 H 줄에 각 W 글자로 게임판의 모양이 주어집니다. # 은 검은 칸, . 는 흰 칸을 나타냅니다. 입력에 주어지는 게임판에 있는 흰 칸의 수는 50 을 넘지 않습니다.

출력
한 줄에 하나씩 흰 칸을 모두 덮는 방법의 수를 출력합니다.
*/


int main()
{
	int TC;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		Result = DotCount = 0;
		cin >> H;
		cin >> W;
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				cin >> Map[j][k];
				if (Map[j][k] == '.')
					DotCount++;
			}
		}
		if (DotCount == 0)
			Result = 1;
		else if (DotCount % 3 == 0)
			Solve(0, 0, 0);

		cout << Result << endl;
	}

	return 0;
}

void Solve(int CurX, int CurY, int Count)
{
	if (Count * 3 == DotCount) {
		Result++;
		return;
	}
	int X, Y;
	X = CurX;
	Y = CurY;
	FindTarget(X, Y);

	if ((X + 1 >= 0 && X + 1 < H && Y + 1 >= 0 && Y + 1 < W) && (Map[X + 1][Y] == '.' && Map[X + 1][Y + 1] == '.')) {
		Map[X][Y] = Map[X + 1][Y] = Map[X + 1][Y + 1] = '#';
		Solve(X, Y, Count + 1);
		Map[X][Y] = Map[X + 1][Y] = Map[X + 1][Y + 1] = '.';
	}
	if ((X + 1 >= 0 && X + 1 < H && Y + 1 >= 0 && Y + 1 < W) && (Map[X][Y + 1] == '.' && Map[X + 1][Y + 1] == '.'))
	{
		Map[X][Y] = Map[X][Y + 1] = Map[X + 1][Y + 1] = '#';
		Solve(X, Y, Count + 1);
		Map[X][Y] = Map[X][Y + 1] = Map[X + 1][Y + 1] = '.';
	}
	if ((X + 1 >= 0 && X + 1 < H && Y + 1 >= 0 && Y + 1 < W) && (Map[X][Y + 1] == '.' && Map[X + 1][Y] == '.'))
	{
		Map[X][Y] = Map[X][Y + 1] = Map[X + 1][Y] = '#';
		Solve(X, Y, Count + 1);
		Map[X][Y] = Map[X][Y + 1] = Map[X + 1][Y] = '.';
	}
	if ((X + 1 >= 0 && X + 1 < H && Y - 1 >= 0 && Y - 1 < W) && (Map[X + 1][Y - 1] == '.' && Map[X + 1][Y] == '.'))
	{
		Map[X][Y] = Map[X + 1][Y - 1] = Map[X + 1][Y] = '#';
		Solve(X, Y, Count + 1);
		Map[X][Y] = Map[X + 1][Y - 1] = Map[X + 1][Y] = '.';
	}
}

void FindTarget(int& X, int& Y)
{
	for (X; X < H; X++) {
		for (Y; Y < W; Y++) {
			if (Map[X][Y] == '.')
				return;
		}
		Y = 0;
	}
}