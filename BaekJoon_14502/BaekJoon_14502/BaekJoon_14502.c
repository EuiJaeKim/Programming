#include <stdio.h>

int N, M;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int Map[8][8] = { 0, };
int VirusMap[10][2];
int VirusCnt;
int ZeroCnt;
int Max;

void Init();
void Solve(int CurMap[8][8], int WallCnt, int CurX, int CurY);
int TimeFlow(int CurMap[8][8], int X, int Y);

int main()
{
	Init();
	Solve(Map, 0, 0, 0);
	printf("%d", Max);
	return 0;
}

void Init()
{
	scanf("%d %d", &N, &M);
	ZeroCnt = Max = VirusCnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &Map[i][j]);
			if (Map[i][j] == 0)
				ZeroCnt++;
			else if (Map[i][j] == 2) {
				VirusMap[VirusCnt][0] = i;
				VirusMap[VirusCnt++][1] = j;
			}
		}
	}
	ZeroCnt -= 3;
}

void Solve(int CurMap[8][8], int WallCnt, int CurX, int CurY)
{
	if (WallCnt < 3) {
		for (int i = CurX; i < N; i++) {
			for (int j = CurY; j < M; j++) {
				if (CurMap[i][j] == 0) {
					CurMap[i][j] = 1;
					Solve(CurMap, WallCnt + 1, CurX, CurY);
					CurMap[i][j] = 0;
					if (ZeroCnt == Max)
						return;
				}
			}
		}
	}
	else {
		int TempMap[8][8];
		int Cnt = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				TempMap[i][j] = CurMap[i][j];
		for (int i = 0; i < VirusCnt; i++) {
			Cnt += TimeFlow(TempMap, VirusMap[i][0], VirusMap[i][1]);
		}
		if (ZeroCnt - Cnt > Max)
			Max = ZeroCnt - Cnt;
	}
}

int TimeFlow(int CurMap[8][8], int X, int Y)
{
	int CurX, CurY;
	int Cnt = 0;
	for (int j = 0; j < 4; j++) {
		CurX = X;
		CurY = Y;
		if (CurX + dx[j] >= 0 && CurX + dx[j] < N && CurY + dy[j] >= 0 && CurY + dy[j] < M && CurMap[CurX + dx[j]][CurY + dy[j]] == 0) {
			CurMap[CurX + dx[j]][CurY + dy[j]] = 2;
			Cnt++;
			Cnt += TimeFlow(CurMap, CurX + dx[j], CurY + dy[j]);
		}
	}
	return Cnt;
}