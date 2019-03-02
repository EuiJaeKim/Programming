#include <iostream>

#define Max 8
#define RangeCheck(A,B) A > -1 ? A < N ? B >-1 ? B < M ? true : false : false : false : false
using namespace std;

int Map[Max][Max];
int Virus[10][2];
int VirusCount;
int infectionCount;
int ZeroCount;
int Result;
int N, M, SaftyZone;

void Init();
void Wall(int Count, int X, int Y);
void infect(int X, int Y);

int main()
{
	Init();
	Wall(0, 0, 0);
	cout << Result;
	return 0;
}

void Init()
{
	VirusCount = Result = 0;
	ZeroCount = -3;
	cin >> N >> M;

	for ( int i = 0; i < N; i++) {
		for ( int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) {
				Virus[VirusCount][0] = i;
				Virus[VirusCount++][1] = j;
			}
			else if (Map[i][j] == 0)
				ZeroCount++;
		}
	}
}

void Wall(int Count, int X, int Y)
{
	if (Count == 3) {
		infectionCount = 0;
		for ( int i = 0; i < VirusCount; i++) {
			infect(Virus[i][0], Virus[i][1]);
		}
		int Temp;
		Temp = ZeroCount - infectionCount;
		if (Result < Temp)
			Result = Temp;
		for ( int i = 0; i < N; i++) {
			for ( int j = 0; j < M; j++) {
				if (Map[i][j] == 2)
					Map[i][j] = 0;
			}
		}
		for (register int i = 0; i < VirusCount; i++) {
			Map[Virus[i][0]][Virus[i][1]] = 2;
		}
		return;
	}
	else {
		int j = Y;
		for ( int i = X; i < N; i++) {
			for ( ; j < M; j++) {
				if (Map[i][j] == 0) {
					Map[i][j] = 1;
					Wall(Count + 1, i, j + 1);
					Map[i][j] = 0;
				}
			}
			j = 0;
		}
	}
}

void infect(int X, int Y)
{
	if (RangeCheck(X - 1, Y)) {
		if (Map[X - 1][Y] == 0) {
			infectionCount++;
			Map[X - 1][Y] = 2;
			infect(X - 1, Y);
		}
	}

	if (RangeCheck(X + 1, Y)) {
		if (Map[X + 1][Y] == 0) {
			infectionCount++;
			Map[X + 1][Y] = 2;
			infect(X + 1, Y);
		}
	}

	if (RangeCheck(X, Y - 1)) {
		if (Map[X][Y - 1] == 0) {
			infectionCount++;
			Map[X][Y - 1] = 2;
			infect(X, Y - 1);
		}
	}

	if (RangeCheck(X, Y + 1)) {
		if (Map[X][Y + 1] == 0) {
			infectionCount++;
			Map[X][Y + 1] = 2;
			infect(X, Y + 1);
		}
	}
}