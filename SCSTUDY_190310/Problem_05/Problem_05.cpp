#include <iostream>
#include <cstring>
using namespace std;

int Map[30][10];
int N; // 세로선의 개수
int M; // 가로선의 개수
int H; // 세로선마다 가로선을 놓을 수 있는 위치의 개수

void Init()
{
	int X, Y;
	memset(Map, 0, sizeof(Map));
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> X >> Y;
		Map[X - 1][Y - 1] = 1;
		Map[X - 1][Y] = -1;
	}
}
// 0 1 2 3
bool Solve(int Count, int X, int Y)
{
	if (Count == 0) {
		int Sum;
		for (int i = 0; i < N; i++) {
			Sum = i;
			for (int j = 0; j < H; j++) {
				Sum += Map[j][Sum];
			}
			if (Sum != i)
				return false;
		}
		return true;
	}
	else {
		int CurX = X + 1;
		for (int CurY = Y; CurY < N - 1; CurY++) {
			for (; CurX < H; CurX++) {
				if (Map[CurX][CurY] == 0 && Map[CurX][CurY + 1] == 0) {
					Map[CurX][CurY] = 1;
					Map[CurX][CurY + 1] = -1;
					if (Solve(Count - 1, CurX, CurY))
						return true;
					Map[CurX][CurY] = Map[CurX][CurY + 1] = 0;
				}
			}
			CurX = 0;
		}
	}
	return false;
}

int main()
{
	Init();
	for (int i = 0; i < 4; i++) {
		if (Solve(i, 0, 0)) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}