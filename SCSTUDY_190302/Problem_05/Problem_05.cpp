#include <iostream>

#define Max 20
#define RangeCheck(A,B) A > -1 ? A < H ? B >-1 ? B < W ? true : false : false : false : false
using namespace std;

char Map[Max][Max];
int Tank[2];
int H, W;
int Order;

void Init();
void Play(char order)
{
	if (order == 'U') {
		Map[Tank[0]][Tank[1]] = '^';
		if (RangeCheck(Tank[0] - 1, Tank[1])) {
			if (Map[Tank[0] - 1][Tank[1]] == '.') {
				Map[Tank[0] - 1][Tank[1]] = Map[Tank[0]][Tank[1]];
				Map[Tank[0]][Tank[1]] = '.';
				Tank[0] -= 1;
			}
		}
	}
	else if (order == 'D') {
		Map[Tank[0]][Tank[1]] = 'v';
		if (RangeCheck(Tank[0] + 1, Tank[1])) {
			if (Map[Tank[0] + 1][Tank[1]] == '.') {
				Map[Tank[0] + 1][Tank[1]] = Map[Tank[0]][Tank[1]];
				Map[Tank[0]][Tank[1]] = '.';
				Tank[0] += 1;
			}
		}
	}
	else if (order == 'L') {
		Map[Tank[0]][Tank[1]] = '<';
		if (RangeCheck(Tank[0], Tank[1] - 1)) {
			if (Map[Tank[0]][Tank[1] - 1] == '.') {
				Map[Tank[0]][Tank[1] - 1] = Map[Tank[0]][Tank[1]];
				Map[Tank[0]][Tank[1]] = '.';
				Tank[1] -= 1;
			}
		}
	}
	else if (order == 'R') {
		Map[Tank[0]][Tank[1]] = '>';
		if (RangeCheck(Tank[0], Tank[1] + 1)) {
			if (Map[Tank[0]][Tank[1] + 1] == '.') {
				Map[Tank[0]][Tank[1] + 1] = Map[Tank[0]][Tank[1]];
				Map[Tank[0]][Tank[1]] = '.';
				Tank[1] +=1;
			}
		}
	}
	else if (order == 'S') {
		if (Map[Tank[0]][Tank[1]] == '^') {
			int x, y;
			x = Tank[0];
			y = Tank[1];
			while (RangeCheck(x - 1, y)) {
				if (Map[x - 1][y] == '#')
					break;
				else if (Map[x - 1][y] == '*') {
					Map[x - 1][y] = '.';
					break;
				}
				x--;
			}
		}
		else if (Map[Tank[0]][Tank[1]] == 'v') {
			int x, y;
			x = Tank[0];
			y = Tank[1];
			while (RangeCheck(x + 1, y)) {
				if (Map[x + 1][y] == '#')
					break;
				else if (Map[x + 1][y] == '*') {
					Map[x + 1][y] = '.';
					break;
				}
				x++;
			}
		}
		else if (Map[Tank[0]][Tank[1]] == '>') {
			int x, y;
			x = Tank[0];
			y = Tank[1];
			while (RangeCheck(x, y + 1)) {
				if (Map[x][y + 1] == '#')
					break;
				else if (Map[x][y + 1] == '*') {
					Map[x][y + 1] = '.';
					break;
				}
				y++;
			}
		}
		else if (Map[Tank[0]][Tank[1]] == '<') {
			int x, y;
			x = Tank[0];
			y = Tank[1];
			while (RangeCheck(x, y - 1)) {
				if (Map[x][y - 1] == '#')
					break;
				else if (Map[x][y - 1] == '*') {
					Map[x][y - 1] = '.';
					break;
				}
				y--;
			}
		}
	}
}

int main()
{
	int TC;
	char Temp;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Init();
		for (int j = 0; j < Order; j++) {
			cin >> Temp;
			Play(Temp);
		}
		printf("#%d ", i);
		for (int j = 0; j < H; j++) {
			for (int k = 0; k < W; k++) {
				cout << Map[j][k];
			}
			cout << endl;
		}

	}


	return 0;
}

void Init()
{
	cin >> H >> W;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == '<' || Map[i][j] == '>' || Map[i][j] == '^' || Map[i][j] == 'v') {
				Tank[0] = i;
				Tank[1] = j;
			}
		}
	}
	cin >> Order;
}