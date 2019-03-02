#include <iostream>
#include <string.h>

#define Max 8

using namespace std;

int N, M;
int Map[Max][Max];
int InitMap[Max][Max];
int CCTV[Max][2];
int ZeroCount;
int ViewCount;
int CCTVCount;
int Min;
int CCTVArray[Max];

void Init();
bool RangeCheck(int A, int B)
{
	if (A > -1 && A < N && B > -1 && B < M)
		return true;
	else
		return false;

}
void Solve(int Count);
void Check(int CCTVNum, int Dir);

int main()
{
	Init();
	Solve(0);
	cout << Min;
	return 0;
}

void Init()
{
	CCTVCount = ZeroCount = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			InitMap[i][j] = Map[i][j];
			if (Map[i][j] == 0)
				ZeroCount++;
			else if (Map[i][j] > 0 && Map[i][j] < 6) {
				CCTV[CCTVCount][0] = i;
				CCTV[CCTVCount++][1] = j;
			}
		}
	}
	Min = ZeroCount;
}

void Solve(int Count)
{
	if (Count == CCTVCount) {
		ViewCount = 0;
		for (int i = 0; i < Count; i++) {
			Check(i, CCTVArray[i]);
		}
		if (ZeroCount - ViewCount < Min)
			Min = ZeroCount - ViewCount;
		memcpy(Map, InitMap, sizeof(InitMap));
	}
	else {
		if (Map[CCTV[Count][0]][CCTV[Count][1]] == 1) {
			for (int i = 0; i < 4; i++) {
				CCTVArray[Count] = i;
				Solve(Count + 1);
			}
		}
		else if (Map[CCTV[Count][0]][CCTV[Count][1]] == 2) {
			for (int i = 0; i < 2; i++) {
				CCTVArray[Count] = i;
				Solve(Count + 1);
			}
		}
		else if (Map[CCTV[Count][0]][CCTV[Count][1]] == 3) {
			for (int i = 0; i < 4; i++) {
				CCTVArray[Count] = i;
				Solve(Count + 1);
			}
		}
		else if (Map[CCTV[Count][0]][CCTV[Count][1]] == 4) {
			for (int i = 0; i < 4; i++) {
				CCTVArray[Count] = i;
				Solve(Count + 1);
			}
		}
		else if (Map[CCTV[Count][0]][CCTV[Count][1]] == 5) {
			CCTVArray[Count] = 0;
			Solve(Count + 1);
		}
	}


}

/* Dir : 0 > 위 , 1 > 오른쪽 , 2 > 아래 , 3 > 왼쪽 */
void Check(int CCTVNum, int Dir)
{
	int x[4], y[4];
	switch (Map[CCTV[CCTVNum][0]][CCTV[CCTVNum][1]])
	{
	case 1:
		x[0] = CCTV[CCTVNum][0];
		y[0] = CCTV[CCTVNum][1];
		if (Dir == 0) {
			while (RangeCheck(x[0] - 1, y[0])) {
				if (Map[x[0] - 1][y[0]] == 6)
					break;
				else if (Map[x[0] - 1][y[0]] == 0) {
					ViewCount++;
					Map[x[0] - 1][y[0]] = 7;
				}
				x[0]--;
			}
		}
		else if (Dir == 1) {
			while (RangeCheck(x[0], y[0] + 1)) {
				if (Map[x[0]][y[0] + 1] == 6)
					break;
				else if (Map[x[0]][y[0] + 1] == 0) {
					ViewCount++;
					Map[x[0]][y[0] + 1] = 7;
				}
				y[0]++;
			}
		}
		else if (Dir == 2) {
			while (RangeCheck(x[0] + 1, y[0])) {
				if (Map[x[0] + 1][y[0]] == 6)
					break;
				else if (Map[x[0] + 1][y[0]] == 0) {
					ViewCount++;
					Map[x[0] + 1][y[0]] = 7;
				}
				x[0]++;
			}
		}
		else if (Dir == 3) {
			while (RangeCheck(x[0], y[0] - 1)) {
				if (Map[x[0]][y[0] - 1] == 6)
					break;
				else if (Map[x[0]][y[0] - 1] == 0) {
					ViewCount++;
					Map[x[0]][y[0] - 1] = 7;
				}
				y[0]--;
			}
		}
		break;
	case 2:
		x[0] = x[1] = CCTV[CCTVNum][0];
		y[0] = y[1] = CCTV[CCTVNum][1];
		if (Dir == 0) {
			while (RangeCheck(x[0], y[0] - 1) || RangeCheck(x[1], y[1] + 1)) {
				if (RangeCheck(x[0], y[0] - 1) && Map[x[0]][y[0] - 1] < 1) {
					ViewCount++;
					Map[x[0]][y[0] - 1] = 7;
				}
				if (RangeCheck(x[0], y[0] - 1) && Map[x[0]][y[0] - 1] == 6) {
					y[0] = -1;
				}
				y[0]--;
				if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] < 1) {
					ViewCount++;
					Map[x[1]][y[1] + 1] = 7;
				}
				if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] == 6)
					y[1] = Max;
				y[1]++;
			}
		}
		else if (Dir == 1) {
			while (RangeCheck(x[0] - 1, y[0]) || RangeCheck(x[1] + 1, y[1])) {
				if (RangeCheck(x[0] - 1, y[0]) && Map[x[0] - 1][y[0]] < 1) {
					ViewCount++;
					Map[x[0] - 1][y[0]] = 7;
				}
				if (RangeCheck(x[0] - 1, y[0]) && Map[x[0] - 1][y[0]] == 6)
					x[0] = 0;
				x[0]--;
				if (RangeCheck(x[1] + 1, y[1]) && Map[x[1] + 1][y[1]] < 1) {
					ViewCount++;
					Map[x[1] + 1][y[1]] = 7;
				}
				if (RangeCheck(x[1] + 1, y[1]) && Map[x[1] + 1][y[1]] == 6)
					x[1] = Max;
				x[1]++;
			}
		}
		break;
	case 3:
		x[0] = x[1] = CCTV[CCTVNum][0];
		y[0] = y[1] = CCTV[CCTVNum][1];
		if (Dir == 0) {
			while (RangeCheck(x[0] - 1, y[0]) || RangeCheck(x[1], y[1] + 1)) {
				if (RangeCheck(x[0] - 1, y[0]) && Map[x[0] - 1][y[0]] < 1) {
					ViewCount++;
					Map[x[0] - 1][y[0]] = 7;
				}
				if (RangeCheck(x[0] - 1, y[0]) && Map[x[0] - 1][y[0]] == 6)
					x[0] = 0;
				x[0]--;
				if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] < 1) {
					ViewCount++;
					Map[x[1]][y[1] + 1] = 7;
				}
				if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] == 6)
					y[1] = Max;
				y[1]++;
			}
		}
		else if (Dir == 1) {
			while (RangeCheck(x[0] + 1, y[0]) || RangeCheck(x[1], y[1] + 1)) {
				if (RangeCheck(x[0] + 1, y[0]) && Map[x[0] + 1][y[0]] < 1) {
					ViewCount++;
					Map[x[0] + 1][y[0]] = 7;
				}
				if (RangeCheck(x[0] + 1, y[0]) && Map[x[0] + 1][y[0]] == 6)
					x[0] = Max;
				x[0]++;
				if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] < 1) {
					ViewCount++;
					Map[x[1]][y[1] + 1] = 7;
				}
				if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] == 6)
					y[1] = Max;
				y[1]++;
			}
		}
		else if (Dir == 2) {
			while (RangeCheck(x[0] + 1, y[0]) || RangeCheck(x[1], y[1] - 1)) {
				if (RangeCheck(x[0] + 1, y[0]) && Map[x[0] + 1][y[0]] < 1) {
					ViewCount++;
					Map[x[0] + 1][y[0]] = 7;
				}
				if (RangeCheck(x[0] + 1, y[0]) && Map[x[0] + 1][y[0]] == 6)
					x[0] = Max;
				x[0]++;
				if (RangeCheck(x[1], y[1] - 1) && Map[x[1]][y[1] - 1] < 1) {
					ViewCount++;
					Map[x[1]][y[1] - 1] = 7;
				}
				if (RangeCheck(x[1], y[1] - 1) && Map[x[1]][y[1] - 1] == 6)
					y[1] = 0;
				y[1]--;
			}
		}
		else if (Dir == 3) {
			while (RangeCheck(x[0] - 1, y[0]) || RangeCheck(x[1], y[1] - 1)) {
				if (RangeCheck(x[0] - 1, y[0]) && Map[x[0] - 1][y[0]] < 1) {
					ViewCount++;
					Map[x[0] - 1][y[0]] = 7;
				}
				if (RangeCheck(x[0] - 1, y[0]) && Map[x[0] - 1][y[0]] == 6)
					x[0] = 0;
				x[0]--;
				if (RangeCheck(x[1], y[1] - 1) && Map[x[1]][y[1] - 1] < 1) {
					ViewCount++;
					Map[x[1]][y[1] - 1] = 7;
				}
				if (RangeCheck(x[1], y[1] - 1) && Map[x[1]][y[1] - 1] == 6)
					y[1] = 0;
				y[1]--;
			}
		}
		break;
	case 4:
		x[0] = x[1] = x[2] = CCTV[CCTVNum][0];
		y[0] = y[1] = y[2] = CCTV[CCTVNum][1];
		if (Dir == 0) {
			while (RangeCheck(x[0] - 1, y[0]) || RangeCheck(x[1], y[1] + 1) || RangeCheck(x[2], y[2] - 1)) {
				if (RangeCheck(x[0] - 1, y[0]) && Map[x[0] - 1][y[0]] < 1) {
					ViewCount++;
					Map[x[0] - 1][y[0]] = 7;
				}
				if (RangeCheck(x[0] - 1, y[0]) && Map[x[0] - 1][y[0]] == 6)
					x[0] = 0;
				x[0]--;
				if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] < 1) {
					ViewCount++;
					Map[x[1]][y[1] + 1] = 7;
				}
				if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] == 6)
					y[1] = Max;
				y[1]++;
				if (RangeCheck(x[2], y[2] - 1) && Map[x[2]][y[2] - 1] < 1) {
					ViewCount++;
					Map[x[2]][y[2] - 1] = 7;
				}
				if (RangeCheck(x[2], y[2] - 1) && Map[x[2]][y[2] - 1] == 6)
					y[2] = 0;
				y[2]--;
			}
		}
		else if (Dir == 1) {
			while (RangeCheck(x[0] - 1, y[0]) || RangeCheck(x[1], y[1] + 1) || RangeCheck(x[2] + 1, y[2])) {
				if (RangeCheck(x[0] - 1, y[0]) && Map[x[0] - 1][y[0]] < 1) {
					ViewCount++;
					Map[x[0] - 1][y[0]] = 7;
				}
				if (RangeCheck(x[0] - 1, y[0]) && Map[x[0] - 1][y[0]] == 6)
					x[0] = 0;
				x[0]--;
				if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] < 1) {
					ViewCount++;
					Map[x[1]][y[1] + 1] = 7;
				}
				if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] == 6)
					y[1] = Max;
				y[1]++;
				if (RangeCheck(x[2] + 1, y[2]) && Map[x[2] + 1][y[2]] < 1) {
					ViewCount++;
					Map[x[2] + 1][y[2]] = 7;
				}
				if (RangeCheck(x[2] + 1, y[2]) && Map[x[2] + 1][y[2]] == 6)
					x[2] = Max;
				x[2]++;
			}
		}
		else if (Dir == 2) {
			while (RangeCheck(x[0], y[0] - 1) || RangeCheck(x[1], y[1] + 1) || RangeCheck(x[2] + 1, y[2])) {
				if (RangeCheck(x[0], y[0] - 1) && Map[x[0]][y[0] - 1] < 1) {
					ViewCount++;
					Map[x[0]][y[0] - 1] = 7;
				}
				if (RangeCheck(x[0], y[0] - 1) && Map[x[0]][y[0] - 1] == 6)
					y[0] = 0;
				y[0]--;
				if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] < 1) {
					ViewCount++;
					Map[x[1]][y[1] + 1] = 7;
				}
				if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] == 6)
					y[1] = Max;
				y[1]++;
				if (RangeCheck(x[2] + 1, y[2]) && Map[x[2] + 1][y[2]] < 1) {
					ViewCount++;
					Map[x[2] + 1][y[2]] = 7;
				}
				if (RangeCheck(x[2] + 1, y[2]) && Map[x[2] + 1][y[2]] == 6)
					x[2] = Max;
				x[2]++;
			}
		}
		else if (Dir == 3) {
			while (RangeCheck(x[0], y[0] - 1) || RangeCheck(x[1] - 1, y[1]) || RangeCheck(x[2] + 1, y[2])) {
				if (RangeCheck(x[0], y[0] - 1) && Map[x[0]][y[0] - 1] < 1) {
					ViewCount++;
					Map[x[0]][y[0] - 1] = 7;
				}
				if (RangeCheck(x[0], y[0] - 1) && Map[x[0]][y[0] - 1] == 6)
					y[0] = 0;
				y[0]--;
				if (RangeCheck(x[1] - 1, y[1]) && Map[x[1] - 1][y[1]] < 1) {
					ViewCount++;
					Map[x[1] - 1][y[1]] = 7;
				}
				if (RangeCheck(x[1] - 1, y[1]) && Map[x[1] - 1][y[1]] == 6)
					x[1] = 0;
				x[1]--;
				if (RangeCheck(x[2] + 1, y[2]) && Map[x[2] + 1][y[2]] < 1) {
					ViewCount++;
					Map[x[2] + 1][y[2]] = 7;
				}
				if (RangeCheck(x[2] + 1, y[2]) && Map[x[2] + 1][y[2]] == 6)
					x[2] = Max;
				x[2]++;
			}
		}
		break;
	case 5:
		x[0] = x[1] = x[2] = x[3] = CCTV[CCTVNum][0];
		y[0] = y[1] = y[2] = y[3] = CCTV[CCTVNum][1];
		while (RangeCheck(x[0], y[0] - 1) || RangeCheck(x[1], y[1] + 1) || RangeCheck(x[2] - 1, y[2]) || RangeCheck(x[3] + 1, y[3])) {
			if (RangeCheck(x[0], y[0] - 1) && Map[x[0]][y[0] - 1] < 1) {
				ViewCount++;
				Map[x[0]][y[0] - 1] = 7;
			}
			if (RangeCheck(x[0], y[0] - 1) && Map[x[0]][y[0] - 1] == 6)
				y[0] = 0;
			y[0]--;
			if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] < 1) {
				ViewCount++;
				Map[x[1]][y[1] + 1] = 7;
			}
			if (RangeCheck(x[1], y[1] + 1) && Map[x[1]][y[1] + 1] == 6)
				y[1] = Max;
			y[1]++;
			if (RangeCheck(x[2] - 1, y[2]) && Map[x[2] - 1][y[2]] < 1) {
				ViewCount++;
				Map[x[2] - 1][y[2]] = 7;
			}
			if (RangeCheck(x[2] - 1, y[2]) && Map[x[2] - 1][y[2]] == 6)
				x[2] = 0;
			x[2]--;
			if (RangeCheck(x[3] + 1, y[3]) && Map[x[3] + 1][y[3]] < 1) {
				ViewCount++;
				Map[x[3] + 1][y[3]] = 7;
			}
			if (RangeCheck(x[3] + 1, y[3]) && Map[x[3] + 1][y[3]] == 6)
				x[3] = Max;
			x[3]++;
		}

		break;
	}

}