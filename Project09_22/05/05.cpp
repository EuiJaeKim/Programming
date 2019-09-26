#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int M, N;
int CN, CM;
#define RangeCheck(a,b) a >=0 ? a<=N ? b >= 0 ? b <= M ? true : false : false : false : false
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool Visit[25][25] = { 0, };

typedef struct MyStruct
{
	int X;
	int Y;
} Node;
unsigned long long Map[25][25];
queue<Node> q;

double Distance(int x, int y, int x2, int y2) {
	return sqrt(pow(x - x2, 2) + pow(y - y2, 2));
}

void BFS() {
	Node Cur;

	while (!q.empty()) {
		Cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (RangeCheck(Cur.X + dx[i], Cur.Y + dy[i])) {
				if (Distance(Cur.X, Cur.Y, CM, CN) >= Distance(Cur.X + dx[i], Cur.Y + dy[i], CM, CN)) {
					Map[Cur.X + dx[i]][Cur.Y + dy[i]] += Map[Cur.X][Cur.Y];
					if (!Visit[Cur.X + dx[i]][Cur.Y + dy[i]]) {
						Node* p = new Node;
						p->X = Cur.X + dx[i];
						p->Y = Cur.Y + dy[i];
						q.push(*p);
						Visit[Cur.X + dx[i]][Cur.Y + dy[i]] = true;
					}
				}
			}
		}
	}
}

int main(void) {

	Node* p = new Node;
	p->X = 0;
	p->Y = 0;

	cin >> N >> M;
	cin >> CN >> CM;
	Map[0][0] = 1;
	Visit[0][0] = true;
	q.push(*p);
	if (CN > N || CM > M || CN < 0 || CM < 0)
		cout << "fail";
	else {
		cout << CN + CM << endl;
		if (CN == 0 && CM == 0)
			cout << 0;
		else {
			BFS();
			cout << Map[CM][CN];
		}
	}

	return 0;
}