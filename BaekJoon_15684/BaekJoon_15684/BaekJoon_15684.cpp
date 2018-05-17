#include <iostream>

using namespace std;

int N; // 2 이상 10이하 세로선 2 ≤ N ≤ 10
int M; // 초기 0이상 N*H 이하 가로선 0 ≤ M ≤ N×H
int H; // 가로선 1이상 30 이하  1 ≤ H ≤ 30

int Map[30][10]; // 0 이면 빈거 1이면 오른쪽으로 2이면 왼쪽으로
int Max;

void Init();
int dfs(int Count, int X, int Y);
int Play();

int main()
{
	int x, y;

	cin >> N;
	cin >> M;
	cin >> H;

	Init();
	for (int j = 0; j < M; j++) {
		// 1 ≤ a ≤ H, 1 ≤ b ≤ N-1 b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다는 의미이다.
		cin >> x;
		cin >> y;
		Map[x - 1][y - 1] = 1;
		Map[x - 1][y] = 2;
	}
	dfs(0, 0, 0);
	if (Max < 4)
		cout << Max << endl;
	else
		cout << "-1" << endl;


	return 0;
}

void Init()
{
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 10; j++)
			Map[i][j] = 0;
	Max = 4;
}

int dfs(int Count, int X, int Y)
{
	if (Count > 3)
		return -1;
	int Result;

	Result = Play();
	if (Result == 1 && Max > Count) {
		Max = Count;
		return 0;
	}

	if (Count < 3)
	{
		int i, j;
		i = X;
		j = Y;

		while (j < N)
		{
			while (i < H) {
				if (Map[i][j] == 0 && Map[i][j + 1] == 0) {// 가로선 추가가능?
					Map[i][j] = 1;
					Map[i][j + 1] = 2;
					dfs(Count + 1, i, j);
					Map[i][j] = 0;
					Map[i][j + 1] = 0;
					if (Max == 1)
						return 0;
				}
				i++;
			}
			i = 0;
			j++;
		}
	}

	return -1;

}

int Play()
{
	int x, y;
	int Result = 0;


	for (int i = 0; i < N; i++) {
		x = 0;
		y = i;
		while (x < H) {
			if (Map[x][y] == 1)
				y++;
			else if (Map[x][y] == 2)
				y--;
			x++;
		}
		if (i == y)
			Result++;
		else
			return 0;
	}
	return 1;
}