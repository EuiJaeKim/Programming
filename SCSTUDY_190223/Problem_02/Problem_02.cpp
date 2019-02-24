#include <iostream>
#include <cstring>

#define N 4
#define Length 7
#define RangeCheck(X,Y) X>=0 && X<N && Y>=0 && Y<N ? true : false
using namespace std;

int Map[N][N];
int Result;
bool DataBase[10][10][10][10][10][10][10];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void Init();
void Search(int Count, int X, int Y, int str[Length]);

int main()
{
	int TC;
	int str[7];
	cin >> TC;

	for (register int i = 1; i <= TC; i++) {
		Init();
		for (register int x = 0; x < N; x++)
			for (register int y = 0; y < N; y++)
				Search(0, x, y, str);
		printf("#%d %d\n", i, Result);
	}

	return 0;
}

void Init()
{
	Result = 0;
	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}
	memset(DataBase, 0, sizeof(DataBase));
}

void Search(int Count, int X, int Y, int str[Length])
{
	if (Count < Length) {
		for (register int i = 0; i < 4; i++) {
			if (RangeCheck(X + dx[i], Y + dy[i])) {
				str[Count] = Map[X + dx[i]][Y + dy[i]];
				Search(Count + 1, X + dx[i], Y + dy[i], str);
			}
		}
	}
	else {
		if (DataBase[str[0]][str[1]][str[2]][str[3]][str[4]][str[5]][str[6]])
			return;
		else
			DataBase[str[0]][str[1]][str[2]][str[3]][str[4]][str[5]][str[6]] = true;
		Result++;
	}
}
