#include <iostream>

using namespace std;

struct StartNode
{
	bool way[4];
};

int N; // 게임판의 크기 (5 ≤ N ≤ 100)
int Map[100][100] = { 0, };
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };
StartNode StartMap[100][100];

void Init();
int Solve();
int Play(int StartX, int StartY, int Way);
bool IsOver(int StartX, int StartY, int CurX, int CurY);

int main()
{
	int TC;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		Init();
		printf("#%d %d\n", i, Solve());
	}

	return 0;
}

void Init()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			for (int k = 0; k < 4; k++)
				StartMap[i][j].way[k] = false;
		}
}

int Solve()
{
	int Max = 0;
	int Point;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j] == 0) {
				for (int k = 0; k < 4; k++) {
					if (!StartMap[i][j].way[k]) {
						StartMap[i][j].way[k] = true;
						Point = Play(i, j, k);
						int TempX, TempY;
						TempX = i;
						TempY = j;
						while (1) {
							/* 중복 제거로 얻는 이점은 216ms를 168ms로 줄이는 것. */
							if (TempX + dx[k] > -1 && TempX + dx[k]<N && TempY + dy[k]>-1 && TempY + dy[k] < N && Map[TempX + dx[k]][TempY + dy[k]] == 0) {
								StartMap[TempX + dx[k]][TempY + dy[k]].way[k] = true;
								TempX += dx[k];
								TempY += dy[k];
							}
							else
								break;
						}
						if (Max < Point)
							Max = Point;
					}
				}
			}
		}
	}
	return Max;
}
/* 출발 위치로 돌아오거나, 블랙홀에 빠질 때 끝 */
int Play(int StartX, int StartY, int Way)
{
	int CurX = StartX, CurY = StartY, CurWay = Way, Point = 0;

	while (1) {
		if (Map[CurX][CurY] == 0) {
			if (CurX + dx[CurWay] == N) {
				CurWay = 0;
				Point++;
			}
			else if (CurX + dx[CurWay] == -1) {
				CurWay = 3;
				Point++;
			}
			else if (CurY + dy[CurWay] == N) {
				CurWay = 2;
				Point++;
			}
			else if (CurY + dy[CurWay] == -1) {
				CurWay = 1;
				Point++;
			}
			else {
				CurX += dx[CurWay];
				CurY += dy[CurWay];
			}
		}
		else if (Map[CurX][CurY] > 0) {
			int Temp = Map[CurX][CurY];
			if (Temp < 6) {
				Point++;
				if (Temp == 1) {
					switch (CurWay)
					{
					case 0:
						CurWay = 3;
						break;
					case 1:
						CurWay = 2;
						break;
					case 2:
						CurWay = 0;
						break;
					case 3:
						CurWay = 1;
						break;
					}
				}
				else if (Temp == 2) {
					switch (CurWay)
					{
					case 0:
						CurWay = 1;
						break;
					case 1:
						CurWay = 2;
						break;
					case 2:
						CurWay = 3;
						break;
					case 3:
						CurWay = 0;
						break;
					}
				}
				else if (Temp == 3) {
					switch (CurWay)
					{
					case 0:
						CurWay = 2;
						break;
					case 1:
						CurWay = 3;
						break;
					case 2:
						CurWay = 1;
						break;
					case 3:
						CurWay = 0;
						break;
					}
				}
				else if (Temp == 4) {
					switch (CurWay)
					{
					case 0:
						CurWay = 3;
						break;
					case 1:
						CurWay = 0;
						break;
					case 2:
						CurWay = 1;
						break;
					case 3:
						CurWay = 2;
						break;
					}
				}
				else if (Temp == 5) {
					switch (CurWay)
					{
					case 0:
						CurWay = 3;
						break;
					case 1:
						CurWay = 2;
						break;
					case 2:
						CurWay = 1;
						break;
					case 3:
						CurWay = 0;
						break;
					}
				}

				if (CurX + dx[CurWay] == N) {
					CurWay = 0;
					Point++;
				}
				else if (CurX + dx[CurWay] == -1) {
					CurWay = 3;
					Point++;
				}
				else if (CurY + dy[CurWay] == N) {
					CurWay = 2;
					Point++;
				}
				else if (CurY + dy[CurWay] == -1) {
					CurWay = 1;
					Point++;
				}
				else {
					CurX += dx[CurWay];
					CurY += dy[CurWay];
				}
			}
			else {
				bool Flag = false;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (Map[i][j] == Temp && (i != CurX || j != CurY)) {
							CurX = i;
							CurY = j;
							Flag = true;
							break;
						}
					}
					if (Flag)
						break;
				}
				if (CurX + dx[CurWay] == N) {
					CurWay = 0;
					Point++;
				}
				else if (CurX + dx[CurWay] == -1) {
					CurWay = 3;
					Point++;
				}
				else if (CurY + dy[CurWay] == N) {
					CurWay = 2;
					Point++;
				}
				else if (CurY + dy[CurWay] == -1) {
					CurWay = 1;
					Point++;
				}
				else {
					CurX += dx[CurWay];
					CurY += dy[CurWay];
				}
			}

		}
		else if (Map[CurX][CurY] == -1)
			break;

		if (IsOver(StartX, StartY, CurX, CurY))
			break;
	}

	return Point;
}

bool IsOver(int StartX, int StartY, int CurX, int CurY)
{
	if (StartX == CurX && StartY == CurY)
		return true;
	else
		return false;
}