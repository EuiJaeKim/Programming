#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

#define RangeCheck(a,b) a >=0 ? a<N ? b >= 0 ? b < N ? true : false : false : false : false

using namespace std;

int N, W;
string p[100][100];
string* Pointerp[50];
short Visit[100][100];

void Solve();

int main() {

	string Input;
	memset(Visit, 0, sizeof(Visit));
	cin >> N >> W;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Input;
			p[i][j] = Input;
		}
	}
	Solve();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j + 1 < N)
				cout << p[i][j] << " ";
			else
				cout << p[i][j];
		}
		cout << endl;
	}

	return 0;
}

void Solve()
{
	int x, y;
	bool Dir;
	string Test[396];
	int NW = abs(W);

	if (W > 0)
		Dir = true;
	else
		Dir = false;

	for (int i = 0; i < N / 2; i++) {
		x = y = i;
		int Cur = 0;
		int Flag = 0;
		int Row = 0;
		while (Flag < 4) {
			if (Flag == 0) {
				if (RangeCheck(x, y)) {
					if (Visit[x][y] == 0) {
						Test[Cur++] = p[x][y];
						Visit[x][y]++;
						y++;
						Row++;
					}
					else {
						y--;
						x++;
						Flag++;
					}
				}
				else {
					y--;
					x++;
					Flag++;
				}
			}
			else if (Flag == 1) {
				if (RangeCheck(x, y)) {
					if (Visit[x][y] == 0) {
						Test[Cur++] = p[x][y];
						Visit[x][y]++;
						x++;
					}
					else {
						x--;
						y--;
						Flag++;
					}
				}
				else {
					x--;
					y--;
					Flag++;
				}
			}
			else if (Flag == 2) {
				if (RangeCheck(x, y)) {
					if (Visit[x][y] == 0) {
						Test[Cur++] = p[x][y];
						Visit[x][y]++;
						y--;
					}
					else {
						y++;
						x--;
						Flag++;
					}
				}
				else {
					y++;
					x--;
					Flag++;
				}
			}
			else if (Flag == 3) {
				if (RangeCheck(x, y)) {
					if (Visit[x][y] == 0) {
						Test[Cur++] = p[x][y];
						Visit[x][y]++;
						x--;
					}
					else {
						x++;
						Flag++;
					}
				}
				else {
					x++;
					Flag++;
				}
			}
		}
		if (Dir)
			rotate(Test, Test + Cur - (NW % (Row * 2 + (Row - 2) * 2)), Test + (Row * 2 + (Row - 2) * 2));
		else
			rotate(Test, Test + (NW % (Row * 2 + (Row - 2) * 2)), Test + (Row * 2 + (Row - 2) * 2));
		Dir = !Dir;
		x = y = i;
		Flag = Cur = Row = 0;
		while (Flag < 4) {
			if (Flag == 0) {
				if (RangeCheck(x, y)) {
					if (Visit[x][y] == 1) {
						p[x][y] = Test[Cur++];
						Visit[x][y]++;
						y++;
						Row++;
					}
					else {
						y--;
						x++;
						Flag++;
					}
				}
				else {
					y--;
					x++;
					Flag++;
				}
			}
			else if (Flag == 1) {
				if (RangeCheck(x, y)) {
					if (Visit[x][y] == 1) {
						p[x][y] = Test[Cur++];
						Visit[x][y]++;
						x++;
					}
					else {
						x--;
						y--;
						Flag++;
					}
				}
				else {
					x--;
					y--;
					Flag++;
				}
			}
			else if (Flag == 2) {
				if (RangeCheck(x, y)) {
					if (Visit[x][y] == 1) {
						p[x][y] = Test[Cur++];
						Visit[x][y]++;
						y--;
					}
					else {
						y++;
						x--;
						Flag++;
					}
				}
				else {
					y++;
					x--;
					Flag++;
				}
			}
			else if (Flag == 3) {
				if (RangeCheck(x, y)) {
					if (Visit[x][y] == 1) {
						p[x][y] = Test[Cur++];
						Visit[x][y]++;
						x--;
					}
					else {
						x++;
						Flag++;
					}
				}
				else {
					x++;
					Flag++;
				}
			}
		}

	}
}