#include <iostream>
#include <vector>
#include <cstring>

#define RangeCheck(A,B) (A) > -1 ? (A) < N ? (B) > -1 ? (B) < N ? true : false : false : false : false
using namespace std;

int N;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int Map[20][20];
bool Visit[20][20];
int Time;

typedef struct Node
{
	int X;
	int Y;
	int Size;
	int Ate;
}Node;

vector<Node> Queue;
Node Baby;

void Init()
{
	Node Temp;
	cin >> N;
	Time = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 9) {
				Baby.X = i;
				Baby.Y = j;
				Baby.Size = 2;
				Baby.Ate = Map[i][j] = 0;
			}
		}
	}
	memset(Visit, 0, sizeof(Visit));
	Visit[Baby.X][Baby.Y] = true;
	for (int i = 0; i < 4; i++) {
		Temp.X = Baby.X + dx[i];
		Temp.Y = Baby.Y + dy[i];
		if (RangeCheck(Temp.X, Temp.Y)) {
			if (!Visit[Temp.X][Temp.Y] && Map[Temp.X][Temp.Y] <= Baby.Size) {
				Temp.Size = Map[Temp.X][Temp.Y];
				Temp.Ate = 1;
				Visit[Temp.X][Temp.Y] = true;
				Queue.push_back(Temp);
			}
		}
	}
}

void Search()
{
	vector<Node>::iterator iter;
	Node Eat;
	Node Temp;
	while (!Queue.empty()) {
		iter = Queue.begin();
		Eat.Size = -1;
		for (int i = 0; i < Queue.size(); i++) {
			if (Queue[i].Size > 0 && Queue[i].Size < Baby.Size) {
				// 먹을 수 있음
				if (Eat.Size == -1) {
					// 처음으로 발견됬음
					Eat.X = Queue[i].X;
					Eat.Y = Queue[i].Y;
					Eat.Size = Queue[i].Size;
					Eat.Ate = Queue[i].Ate;
				}
				else {
					// 비교해야 할 놈이 있음.
					if (Eat.X > Queue[i].X || (Eat.X == Queue[i].X && Eat.Y > Queue[i].Y)) {
						Eat.X = Queue[i].X;
						Eat.Y = Queue[i].Y;
						Eat.Size = Queue[i].Size;
						Eat.Ate = Queue[i].Ate;
					}
				}
			}
		}
		if (Eat.Size != -1) {
			// 먹을 놈이 있음.
			Time += Eat.Ate;
			Baby.X = Eat.X;
			Baby.Y = Eat.Y;
			Baby.Ate++;
			Map[Eat.X][Eat.Y] = 0;
			if (Baby.Ate == Baby.Size) {
				Baby.Size++;
				Baby.Ate = 0;
			}
			Queue.clear();
			memset(Visit, 0, sizeof(Visit));
			Visit[Baby.X][Baby.Y] = true;
			// 더 탐색할 구역 추가하고
			for (int i = 0; i < 4; i++) {
				Temp.X = Baby.X + dx[i];
				Temp.Y = Baby.Y + dy[i];
				if (RangeCheck(Temp.X, Temp.Y)) {
					if (!Visit[Temp.X][Temp.Y] && Map[Temp.X][Temp.Y] <= Baby.Size) {
						Temp.Size = Map[Temp.X][Temp.Y];
						Temp.Ate = 1;
						Visit[Temp.X][Temp.Y] = true;
						Queue.push_back(Temp);
					}
				}
			}
		}
		else {
			// 먹을 놈이 없음.
			int Qsize = Queue.size();
			for (int i = 0; i < Qsize; i++) {
				// 더 탐색할 구역 추가하고
				for (int j = 0; j < 4; j++) {
					Temp.X = Queue[i].X + dx[j];
					Temp.Y = Queue[i].Y + dy[j];
					if (RangeCheck(Temp.X, Temp.Y)) {
						if (!Visit[Temp.X][Temp.Y] && Map[Temp.X][Temp.Y] <= Baby.Size) {
							Temp.Size = Map[Temp.X][Temp.Y];
							Temp.Ate = Queue[i].Ate + 1;
							Visit[Temp.X][Temp.Y] = true;
							Queue.push_back(Temp);
						}
					}
				}
			}
			// 기존놈들 삭제.
			Queue.erase(Queue.begin(), Queue.begin() + Qsize);
		}
	}
}

int main()
{
	Init();
	Search();
	cout << Time;
	return 0;
}