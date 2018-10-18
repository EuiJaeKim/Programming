#include <iostream>
#include <cstring>

using namespace std;

int N, M;
char Map[20][20];
bool VisitMap[20][20];
int Coin[2][2];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void Init();
int Solve(char CurMap[20][20], int CurCoin[2][2], bool CurVisitMap[20][20], int Depth);

int main()
{
	int Result;
	Init();
	Result = Solve(Map, Coin, VisitMap, 1);
	cout << (Result == 11 ? -1 : Result);
}

void Init()
{
	int CoinCount = 0;
	cin >> N >> M;
	memset(VisitMap, false, sizeof(bool) * 400);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 'o') {
				VisitMap[i][j] = true;
				Coin[CoinCount][0] = i;
				Coin[CoinCount++][1] = j;
			}
		}
	}
}
int Solve(char CurMap[20][20], int CurCoin[2][2], bool CurVisitMap[20][20], int Depth)
{
	char TempMap[20][20];
	int TempCoin[2][2];
	bool TempVisitMap[20][20];
	int Count, Temp, VisitCount;
	int Min = 11;

	if (Depth < 11) {
		for (int i = 0; i < 4; i++) {
			memcpy(TempMap, CurMap, sizeof(char) * 400);
			memcpy(TempVisitMap, CurVisitMap, sizeof(bool) * 400);
			memcpy(TempCoin, CurCoin, sizeof(int) * 4);
			Count = VisitCount = 0;
			for (int j = 0; j < 2; j++) {
				if (CurCoin[j][0] + dx[i] == N || CurCoin[j][0] + dx[i] == -1 || CurCoin[j][1] + dy[i] == M || CurCoin[j][1] + dy[i] == -1)
					Count++;
				else if (TempMap[CurCoin[j][0] + dx[i]][CurCoin[j][1] + dy[i]] != '#') {
					if (TempVisitMap[CurCoin[j][0] + dx[i]][CurCoin[j][1] + dy[i]] == false)
						VisitCount++;
					TempMap[CurCoin[j][0]][CurCoin[j][1]] = '.';
					TempMap[CurCoin[j][0] + dx[i]][CurCoin[j][1] + dy[i]] = 'o';
					TempCoin[j][0] += dx[i];
					TempCoin[j][1] += dy[i];
				}
			}
			if (Count == 0 && VisitCount > 0) {
				Temp = Solve(TempMap, TempCoin, TempVisitMap, Depth + 1);
				if (Min > Temp)
					Min = Temp;
			}
			else if (Count == 1)
				return Depth;
		}
	}
	return Min;
}