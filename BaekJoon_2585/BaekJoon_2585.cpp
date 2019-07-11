#include <iostream>
#include <cstring>
#include <math.h>
#include <queue>

#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
using namespace std;

typedef struct Node {
	int X;
	int Y;
}Node;

Node Map[1002];


int n, k, Min;

int CalFuel(int Distance)
{
	int Ret;
	Ret = Distance / 10;
	if (Distance - (Ret * 10) > 0)
		Ret++;
	return Ret;
}


int CalDistance(int From,int To)
{
	int x = Map[To].X - Map[From].X;
	int y = Map[To].Y - Map[From].Y;
	return CalFuel((int)sqrt(x * x + y * y));
}

bool bfs(int max_cost, int k) {
	bool visit[1002] = { 0, };
	int from, cnt,Tmp;
	queue<Node> q;
	Node* Temp;
	Temp = new Node;
	Temp->X = Temp->Y = 0;
	q.push(*Temp); // from, k

	while (!q.empty()) {
		from = q.front().X;
		cnt = q.front().Y;
		q.pop();

		if (from == n + 1) {
			if (cnt <= k + 1)
				return 1;
			else
				return 0;
		}

		for (int i = 1; i <= n + 1; i++) {
			if (visit[i])
				continue;
			Tmp = CalDistance(i, from);
			if (Tmp <= max_cost) {

				visit[i] = 1;
				Temp = new Node;
				Temp->X = i;
				Temp->Y = cnt + 1;
				q.push(*Temp);
			}
		}
	}

	return 0;
}

int main()
{
	int InputX, InputY, Left, Right, Mid, Temp;
	cin >> n >> k;
	Map[0].X = Map[0].Y = 0;
	Map[n + 1].X = Map[n + 1].Y = 10000;
	for (int i = 1; i <= n; i++) {
		cin >> InputX >> InputY;
		Map[i].X = InputX;
		Map[i].Y = InputY;
	}

	Left = 1;
	Right = 1415;
	while (Left <= Right) {
		Mid = (Left + Right) / 2;
		Temp = bfs(Mid, k);
		if (Temp != 0) {
			Right = Mid -1;
		}
		else
			Left = Mid + 1;
	}
	cout << Left;
	return 0;
}