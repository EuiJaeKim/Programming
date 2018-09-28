#include <iostream>
#include <vector>

using namespace std;

struct CCTV {
	int X;
	int Y;
	int Val;
	int Dir;
};

vector<CCTV> Camera;
int N, M;
int Min;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


void Solve(int Map[8][8], int Cnt);
int DirCount(int Val);
void Bomb(int Map[8][8], int Cnt, int Dir);
void CalCount(int Map[8][8]);

int main()
{
	CCTV Cam;
	int Map[8][8] = { 0, };

	cin >> N >> M;
	Min = 0;
	for (int j = 0; j < N; j++) {
		for (int o = 0; o < M; o++) {
			cin >> Map[j][o];
			if (Map[j][o] > 0 && Map[j][o] < 6) {
				Cam.X = j;
				Cam.Y = o;
				Cam.Val = Map[j][o];
				Cam.Dir = 0;
				Camera.push_back(Cam);
			}
			else if (Map[j][o] == 0)
				Min++;
		}
	}
	if (Camera.size() > 0)
		Solve(Map, 0);

	cout << Min;

	return 0;
}

void Solve(int Map[8][8], int Cnt)
{
	int CurMap[8][8];
	int K = DirCount(Camera[Cnt].Val);

	if (Cnt < Camera.size() - 1) {
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < N; j++)
				for (int k = 0; k < M; k++)
					CurMap[j][k] = Map[j][k];

			Bomb(CurMap, Cnt, i);
			Solve(CurMap, Cnt + 1);
			if (Min == 0)
				return;
		}
	}
	else { // 1°³ ÀÏ¶§
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < N; j++)
				for (int k = 0; k < M; k++)
					CurMap[j][k] = Map[j][k];

			Bomb(CurMap, Cnt, i);
			CalCount(CurMap);
			if (Min == 0)
				return;
		}
	}


}

int DirCount(int Val)
{
	if (Val == 1)
		return 4;
	else if (Val == 2)
		return 2;
	else if (Val == 3)
		return 4;
	else if (Val == 4)
		return 4;
	else
		return 1;
}

void Bomb(int Map[8][8], int Cnt, int Dir)
{
	int CurX, CurY;
	CurX = Camera[Cnt].X;
	CurY = Camera[Cnt].Y;

	if (Camera[Cnt].Val == 1) {
		while (1) {
			if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
				break;
			else if (Map[CurX][CurY] == 0)
				Map[CurX][CurY] = -1;
			CurX += dx[Dir];
			CurY += dy[Dir];
		}
	}
	else if (Camera[Cnt].Val == 2) {
		while (1) {
			if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
				break;
			else if (Map[CurX][CurY] == 0)
				Map[CurX][CurY] = -1;
			CurX += dx[Dir];
			CurY += dy[Dir];
		}
		CurX = Camera[Cnt].X;
		CurY = Camera[Cnt].Y;
		while (1) {
			if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
				break;
			else if (Map[CurX][CurY] == 0)
				Map[CurX][CurY] = -1;
			CurX += dx[Dir + 2];
			CurY += dy[Dir + 2];
		}

	}
	else if (Camera[Cnt].Val == 3) {
		if (Dir == 0) {
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[Dir];
				CurY += dy[Dir];
			}
			CurX = Camera[Cnt].X;
			CurY = Camera[Cnt].Y;
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[Dir + 3];
				CurY += dy[Dir + 3];
			}
		}
		else {
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[Dir];
				CurY += dy[Dir];
			}
			CurX = Camera[Cnt].X;
			CurY = Camera[Cnt].Y;
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[Dir - 1];
				CurY += dy[Dir - 1];
			}
		}
	}
	else if (Camera[Cnt].Val == 4) {
		if (Dir == 0) {
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[Dir];
				CurY += dy[Dir];
			}
			CurX = Camera[Cnt].X;
			CurY = Camera[Cnt].Y;
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[2];
				CurY += dy[2];
			}
			CurX = Camera[Cnt].X;
			CurY = Camera[Cnt].Y;
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[3];
				CurY += dy[3];
			}
		}
		else if (Dir == 1) {
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[Dir];
				CurY += dy[Dir];
			}
			CurX = Camera[Cnt].X;
			CurY = Camera[Cnt].Y;
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[0];
				CurY += dy[0];
			}
			CurX = Camera[Cnt].X;
			CurY = Camera[Cnt].Y;
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[3];
				CurY += dy[3];
			}
		}
		else if (Dir == 2) {
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[Dir];
				CurY += dy[Dir];
			}
			CurX = Camera[Cnt].X;
			CurY = Camera[Cnt].Y;
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[1];
				CurY += dy[1];
			}
			CurX = Camera[Cnt].X;
			CurY = Camera[Cnt].Y;
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[0];
				CurY += dy[0];
			}
		}
		else if (Dir == 3) {
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[Dir];
				CurY += dy[Dir];
			}
			CurX = Camera[Cnt].X;
			CurY = Camera[Cnt].Y;
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[2];
				CurY += dy[2];
			}
			CurX = Camera[Cnt].X;
			CurY = Camera[Cnt].Y;
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[1];
				CurY += dy[1];
			}
		}
	}
	else if (Camera[Cnt].Val == 5) {
		for (int i = 0; i < 4; i++) {
			while (1) {
				if (CurX < 0 || CurX == N || CurY < 0 || CurY == M || Map[CurX][CurY] == 6)
					break;
				else if (Map[CurX][CurY] == 0)
					Map[CurX][CurY] = -1;
				CurX += dx[i];
				CurY += dy[i];
			}
			CurX = Camera[Cnt].X;
			CurY = Camera[Cnt].Y;
		}
	}

}

void CalCount(int Map[8][8])
{
	int Count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 0)
				Count++;
		}
	}
		

	if (Min > Count)
		Min = Count;
}