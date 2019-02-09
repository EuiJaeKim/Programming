#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int Map[100][100];
bool Visit[100][100];
int N;

typedef struct Body {
	int X;
	int Y;
}Body;

vector<Body> Snake;

void Init();
int Solve();
bool Move(int Dir);

int main()
{
	Init();
	printf("%d", Solve());
	return 0;
}

void Init()
{
	int K, X, Y;
	Body Temp;

	memset(Map, 0, sizeof(Map));
	memset(Visit, 0, sizeof(Visit));
	Temp.X = 0;
	Temp.Y = 0;
	Visit[0][0] = true;

	cin >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> X >> Y;
		Map[X - 1][Y - 1] = 1;
	}

	Snake.push_back(Temp);
}

int Solve()
{
	int L, Time, X, Dir; // Dir -> 0 오른쪽 1 아래쪽 2 왼쪽 3 위쪽
	char C;

	Time = Dir = 0;
	cin >> L;

	while (L > 0) {
		cin >> X >> C;

		while (Time < X ) {
			
			if (Time != X) {
				if (!Move(Dir))
					return Time+1;
			}
			Time++;
		}
		if (C == 'D')
			Dir++;
		else
			Dir--;

		if (Dir == -1)
			Dir = 3;
		else if (Dir == 4)
			Dir = 0;

		L--;
	}

	while (1) {
		
		if (!Move(Dir))
			return Time+1;
		Time++;
	}
}

bool Move(int Dir)
{
	int HeadX, HeadY;
	vector<Body>::iterator iter;

	HeadX = Snake[0].X;
	HeadY = Snake[0].Y;

	switch (Dir)
	{
	case 0:
		if (HeadY + 1 >= N) // 1. Map을 넘어가면 끝
			return false;
		if (!Visit[HeadX][HeadY + 1] && Map[HeadX][HeadY + 1] == 0) { // 방문 하지 않았고 사과도 없다면
			if (Snake.size() == 1) { // 2 - 1. Map을 넘어가지 않으면서 진행방향을 보았을 때 갈 수 있고, 사과가 없고, 몸 길이는 1 일때
				Snake[0].Y++;
				Visit[HeadX][HeadY] = false;
				Visit[Snake[0].X][Snake[0].Y] = true;
			}
			else { // 2 - 2. Map을 넘어가지 않으면서 진행방향을 보았을 때 갈 수 있고, 사과가 없고, 몸 길이는 1 이상 일때
				Body Temp;
				iter = Snake.begin();
				Temp.X = HeadX;
				Temp.Y = HeadY + 1;
				Visit[Temp.X][Temp.Y] = true;
				Snake.insert(iter, Temp);

				Temp.X = Snake.back().X;
				Temp.Y = Snake.back().Y;
				Visit[Temp.X][Temp.Y] = false;
				Snake.pop_back();
			}
			return true;
		}
		else if (Visit[HeadX][HeadY + 1]) { // 방문 했다면
			return false; // 3. 방문 했던 곳(뱀의 몸이 있는 곳)이면 끝
		}
		else if(!Visit[HeadX][HeadY + 1] && Map[HeadX][HeadY + 1] == 1) { // 방문 하지 않았고 사과가 있다면
			Map[HeadX][HeadY + 1] = 0; // 4. Map을 넘어가지 않으면서 진행방향을 보았을 때 갈 수 있고, 사과가 있을 때
			Body Temp;
			iter = Snake.begin();
			Temp.X = HeadX;
			Temp.Y = HeadY + 1;
			Snake.insert(iter, Temp);
			return true;
		}
		return false;
		break;
	case 1:
		if (HeadX + 1 >= N)
			return false;
		if (!Visit[HeadX + 1][HeadY] && Map[HeadX + 1][HeadY] == 0) { // 방문 하지 않았고 사과도 없다면
			if (Snake.size() == 1) {
				Snake[0].X++;
				Visit[HeadX][HeadY] = false;
				Visit[Snake[0].X][Snake[0].Y] = true;
			}
			else {
				Body Temp;
				iter = Snake.begin();
				Temp.X = HeadX + 1;
				Temp.Y = HeadY;
				Visit[Temp.X][Temp.Y] = true;
				Snake.insert(iter, Temp);

				Temp.X = Snake.back().X;
				Temp.Y = Snake.back().Y;
				Visit[Temp.X][Temp.Y] = false;
				Snake.pop_back();
			}
			return true;
		}
		else if (Visit[HeadX + 1][HeadY]) { // 방문 했다면
			return false;
		}
		else if (!Visit[HeadX + 1][HeadY] && Map[HeadX + 1][HeadY] == 1) { // 방문 하지 않았고 사과가 있다면
			Map[HeadX + 1][HeadY] = 0;
			Body Temp;
			iter = Snake.begin();
			Temp.X = HeadX + 1;
			Temp.Y = HeadY;
			Snake.insert(iter, Temp);
			return true;
		}
		return false;
		break;
	case 2:
		if (HeadY - 1 < 0)
			return false;
		if (!Visit[HeadX][HeadY - 1] && Map[HeadX][HeadY - 1] == 0) { // 방문 하지 않았고 사과도 없다면
			if (Snake.size() == 1) {
				Snake[0].Y--;
				Visit[HeadX][HeadY] = false;
				Visit[Snake[0].X][Snake[0].Y] = true;
			}
			else {
				Body Temp;
				iter = Snake.begin();
				Temp.X = HeadX;
				Temp.Y = HeadY - 1;
				Visit[Temp.X][Temp.Y] = true;
				Snake.insert(iter, Temp);

				Temp.X = Snake.back().X;
				Temp.Y = Snake.back().Y;
				Visit[Temp.X][Temp.Y] = false;
				Snake.pop_back();
			}
			return true;
		}
		else if (Visit[HeadX][HeadY - 1]) { // 방문 했다면
			return false;
		}
		else if (!Visit[HeadX][HeadY - 1] && Map[HeadX][HeadY - 1] == 1) { // 방문 하지 않았고 사과가 있다면
			Map[HeadX][HeadY - 1] = 0;
			Body Temp;
			iter = Snake.begin();
			Temp.X = HeadX;
			Temp.Y = HeadY - 1;
			Snake.insert(iter, Temp);
			return true;
		}
		return false;
		break;
	case 3:
		if (HeadX - 1 < 0)
			return false;
		if (!Visit[HeadX - 1][HeadY] && Map[HeadX - 1][HeadY] == 0) { // 방문 하지 않았고 사과도 없다면
			if (Snake.size() == 1) {
				Snake[0].X--;
				Visit[HeadX][HeadY] = false;
				Visit[Snake[0].X][Snake[0].Y] = true;
			}
			else {
				Body Temp;
				iter = Snake.begin();
				Temp.X = HeadX - 1;
				Temp.Y = HeadY;
				Visit[Temp.X][Temp.Y] = true;
				Snake.insert(iter, Temp);

				Temp.X = Snake.back().X;
				Temp.Y = Snake.back().Y;
				Visit[Temp.X][Temp.Y] = false;
				Snake.pop_back();
			}
			return true;
		}
		else if (Visit[HeadX - 1][HeadY]) { // 방문 했다면
			return false;
		}
		else if (!Visit[HeadX - 1][HeadY] && Map[HeadX - 1][HeadY] == 1) { // 방문 하지 않았고 사과가 있다면
			Map[HeadX - 1][HeadY] = 0;
			Body Temp;
			iter = Snake.begin();
			Temp.X = HeadX - 1;
			Temp.Y = HeadY;
			Snake.insert(iter, Temp);
			return true;
		}
		return false;
		break;
	}
}