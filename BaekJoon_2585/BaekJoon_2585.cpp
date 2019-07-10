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
bool visit[1002] = { 0, };
int visited[1002] = { 0, };

int n, k, Min;

int CalFuel(double Distance)
{
	int Ret;
	Ret = Distance / 10;
	if (Distance - Ret > 0)
		Ret++;
	return Ret;
}

int CalDistance(int InputX, int InputY, int InputXX, int InputYY)
{
	int x = InputX - InputXX;
	int y = InputY - InputYY;
	return CalFuel((double)sqrt(x * x + y * y));
}

int DFS(int CurK, int Mid, int Start)
{
	int Temp;
	Temp = min(Mid, CalDistance(Map[Start].X, Map[Start].Y, Map[n + 1].X, Map[n + 1].Y));
	if (CurK == 0) {
		if (Temp != Mid && Temp < Mid)
			return Temp;
		else {
			visited[Start] = -1;
			return 0;
		}

	}
	else {
		if (Temp < Mid)
			return Temp;
		for (int i = 1; i <= n; i++) {
			if (visit[i] && visited[i] != -1)
				continue;
			Temp = CalDistance(Map[Start].X, Map[Start].Y, Map[i].X, Map[i].Y);
			if (Temp < Mid) {
				visit[i] = true;
				Temp = DFS(CurK - 1, Mid, i);
				visit[i] = false;
				if (Temp != 0)
					return Temp;
			}
		}
	}
	visited[Start] = -1;
	return 0;
}

bool bfs(int max_cost, int k) {
	memset(visit, 0, sizeof(visit));

	queue<Node> q;
	Node* Temp;
	Temp = new Node;
	Temp->X = Temp->Y = 0;
	q.push(*Temp); // from, k

	while (!q.empty()) {
		int from = q.front().X;
		int cnt = q.front().Y;
		q.pop();

		if (from == n - 1) {
			if (cnt <= k + 1) return 1;
			else return 0;
		}

		for (int i = 1; i < n; i++) {
			if (visit[i]) continue;

			if (CalDistance(Map[i].X, Map[i].Y, Map[from].X, Map[from].Y) <= max_cost) {
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
		//Temp = DFS(k, Mid, Left);
		Temp = bfs(Mid, k);
		if (Temp != 0) {
			Right = Mid - 1;
		}
		else
			Left = Mid + 1;
	}
	cout << Left << endl;
	return 0;
}