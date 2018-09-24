#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct Cell {
	short X;
	short Y;
	short K; // 원자들의 보유 에너지 1≤K≤100
	short P; // 이동 방향은 상(0), 하(1), 좌(2), 우(3)
	float Bomb; // 0 : 폭발 가능성 없음. 0 < 폭발가능성있음.
};

int N; // 원자들의 수 (1≤N≤1,000)
int Result;
vector<Cell> Cells;

void Init();
void Solve();
float IsBomb();
bool Check(Cell A, Cell B);

int main()
{
	int TC;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Init();
		Solve();
		printf("#%d %d\n", i, Result);
	}

	return 0;
}

void Init()
{
	cin >> N;
	Cells.resize(N);
	Result = 0;
	for (int i = 0; i < N; i++) {
		cin >> Cells[i].X >> Cells[i].Y >> Cells[i].P >> Cells[i].K;
		Cells[i].Bomb = 0;
	}
}

void Solve()
{
	float Min;

	while (Cells.size() != 0) {
		Min = IsBomb();
		for (int i = 0; i < Cells.size(); i++) {
			if (Min == Cells[i].Bomb) {
				Result += Cells[i].K;
				Cells.erase(Cells.begin() + i);
				i--;
			}
			else {
				Cells[i].Bomb = 0;
			}
		}
	}
}

float IsBomb()
{
	float Temp;
	float min = 40000;

	for (int i = 0; i < Cells.size(); i++) {
		for (int j = i + 1; j < Cells.size(); j++) {
			if (Cells[i].P + Cells[j].P == 1) {
				if (Cells[i].X == Cells[j].X) {
					if (Cells[i].Y > Cells[j].Y && Cells[i].P == 1) {
						Temp = (float)(Cells[i].Y - Cells[j].Y) / 2;

						if (Cells[i].Bomb == 0)
							Cells[i].Bomb = Temp;
						else {
							if (Cells[i].Bomb > Temp)
								Cells[i].Bomb = Temp;
						}
						if (Cells[j].Bomb == 0)
							Cells[j].Bomb = Temp;
						else {
							if (Cells[j].Bomb > Temp)
								Cells[j].Bomb = Temp;
						}
						if (min > Temp)
							min = Temp;
					}
					else if (Cells[i].Y < Cells[j].Y && Cells[i].P == 0) {
						Temp = (float)(Cells[j].Y - Cells[i].Y) / 2;

						if (Cells[i].Bomb == 0)
							Cells[i].Bomb = Temp;
						else {
							if (Cells[i].Bomb > Temp)
								Cells[i].Bomb = Temp;
						}
						if (Cells[j].Bomb == 0)
							Cells[j].Bomb = Temp;
						else {
							if (Cells[j].Bomb > Temp)
								Cells[j].Bomb = Temp;
						}
						if (min > Temp)
							min = Temp;
					}
				}
			}
			else if (Cells[i].P + Cells[j].P == 5) {
				if (Cells[i].Y == Cells[j].Y) {
					if (Cells[i].X > Cells[j].X && Cells[i].P == 2) {
						Temp = (float)(Cells[i].X - Cells[j].X) / 2;

						if (Cells[i].Bomb == 0)
							Cells[i].Bomb = Temp;
						else {
							if (Cells[i].Bomb > Temp)
								Cells[i].Bomb = Temp;
						}
						if (Cells[j].Bomb == 0)
							Cells[j].Bomb = Temp;
						else {
							if (Cells[j].Bomb > Temp)
								Cells[j].Bomb = Temp;
						}
						if (min > Temp)
							min = Temp;
					}
					else if (Cells[i].X < Cells[j].X && Cells[i].P == 3) {
						Temp = (float)(Cells[j].X - Cells[i].X) / 2;

						if (Cells[i].Bomb == 0)
							Cells[i].Bomb = Temp;
						else {
							if (Cells[i].Bomb > Temp)
								Cells[i].Bomb = Temp;
						}
						if (Cells[j].Bomb == 0)
							Cells[j].Bomb = Temp;
						else {
							if (Cells[j].Bomb > Temp)
								Cells[j].Bomb = Temp;
						}
						if (min > Temp)
							min = Temp;
					}
				}
			}
			// 대각선 체크
			else if (Check(Cells[i], Cells[j])) {
				if (abs(Cells[i].X - Cells[j].X) == abs(Cells[i].Y - Cells[j].Y)) {
					Temp = abs(Cells[i].X - Cells[j].X);

					if (Cells[i].Bomb == 0)
						Cells[i].Bomb = Temp;
					else {
						if (Cells[i].Bomb > Temp)
							Cells[i].Bomb = Temp;
					}
					if (Cells[j].Bomb == 0)
						Cells[j].Bomb = Temp;
					else {
						if (Cells[j].Bomb > Temp)
							Cells[j].Bomb = Temp;
					}
					if (min > Temp)
						min = Temp;
				}
			}
		}
	}
	for (int i = 0; i < Cells.size(); i++) {
		if (Cells[i].Bomb == 0) {
			Cells.erase(Cells.begin() + i);
			i--;
		}
	}
	return min;
}

bool Check(Cell A, Cell B)
{
	if (A.P == 0) {
		if (B.P == 2 && A.X < B.X && A.Y < B.Y)
			return true;
		else if (B.P == 3 && A.X > B.X && A.Y < B.Y)
			return true;
	}
	else if (A.P == 1) {
		if (B.P == 2 && A.X < B.X && A.Y > B.Y)
			return true;
		else if (B.P == 3 && A.X > B.X && A.Y > B.Y)
			return true;
	}
	else if (A.P == 2) {
		if (B.P == 0 && A.X > B.X&& A.Y > B.Y)
			return true;
		else if (B.P == 1 && A.X > B.X && A.Y < B.Y)
			return true;
	}
	else if (A.P == 3) {
		if (B.P == 0 && A.X < B.X && A.Y > B.Y)
			return true;
		else if (B.P == 1 && A.X < B.X && A.Y < B.Y)
			return true;
	}
	return false;
}