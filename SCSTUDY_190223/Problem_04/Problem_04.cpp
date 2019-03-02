#include <iostream>

#define Max 50
using namespace std;

int N, M;
int Result;
int Map[Max][Max]; // 빈칸 0, 벽 1 , 청소된 상태 2
int Robot[3] = { 0, };
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void Init();
void Solve();
int SearchDirReturn(int i);

int main()
{
	Init();
	Solve();
	cout << Result;
	return 0;
}

void Init()
{
	Result = 1;
	cin >> N >> M;
	for (int i = 0; i < 3; i++)
		cin >> Robot[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Map[i][j];
}

void Solve()
{
	int Dir;
	bool Cleaned;

	while (1) {
		Map[Robot[0]][Robot[1]] = 2; // 현재 위치를 청소한다.
		Cleaned = false;
		for (int i = 0; i < 4; i++) {
			Dir = SearchDirReturn(1); // 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
			Robot[2] = Dir;
			if (Map[Robot[0] + dx[Dir]][Robot[1] + dy[Dir]] == 0) { // 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
				Robot[0] += dx[Dir];
				Robot[1] += dy[Dir];
				Cleaned = true;
				Result++;
				break;
			}
		}

		if (!Cleaned) {
			if (Map[Robot[0] - dx[Robot[2]]][Robot[1] - dy[Robot[2]]] == 1)
				break; // 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다
			else { // 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
				Robot[0] -= dx[Robot[2]];
				Robot[1] -= dy[Robot[2]];
			}
		}

	}
}

int SearchDirReturn(int i)
{

	if (Robot[2] - i > -1)
		return Robot[2] - i;
	else
		return 4 + (Robot[2] - i);
}
