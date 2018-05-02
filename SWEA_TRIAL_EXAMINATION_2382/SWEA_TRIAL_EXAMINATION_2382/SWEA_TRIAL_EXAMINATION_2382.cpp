#include <cstdio>
#include <cstdlib>
#define MAX 100
typedef struct Map
{
	int Count; // 미생물 수
	int Direction; // 방향 1상 2하 3좌 4우
	int Move; // 몇번 움직였니
	bool IsWall;
} Map;

Map Board[MAX][MAX];
Map BoardB[MAX][MAX];
int N; // 크기
int K; // 미생물 군집의 수
int M; // 격리 시간

void initMap();
void CopyMap();
void Move(int X, int Y);
void Copy(int X, int Y);
void ForCheck(int X, int Y);
int Solve();

int main()
{
	int TC;
	int X, Y, Count, Dir;
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d", &N);
		scanf("%d", &M);
		scanf("%d", &K);
		initMap();

		for (int j = 0; j < K; j++) {
			scanf("%d %d %d %d", &X, &Y, &Count, &Dir);
			Board[X][Y].Count = Count;
			Board[X][Y].Direction = Dir;
		}
		printf("#%d %d\n", i, Solve());

	}

	return 0;
}

int Solve()
{
	for (int i = 0; i < M; i++) { // 격리 횟수 동안 돌아여
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (Board[j][k].Count > 0)
					Move(j, k);
			}
		}
		CopyMap();
	}

	int Result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Board[i][j].Count != 0) {
				Result += Board[i][j].Count;
			}

		}
	}
	return Result;
}

void initMap()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			Board[i][j].Count = 0;
			BoardB[i][j].Count = 0;
			Board[i][j].Direction = 0;
			BoardB[i][j].Direction = 0;
			Board[i][j].Move = 0;
			BoardB[i][j].Move = 0;
			if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
				Board[i][j].IsWall = BoardB[i][j].IsWall = 1;
			else
				Board[i][j].IsWall = BoardB[i][j].IsWall = 0;
		}
}

void CopyMap()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			Board[i][j].Count = BoardB[i][j].Count;
			BoardB[i][j].Count = 0;
			Board[i][j].Direction = BoardB[i][j].Direction;
			BoardB[i][j].Direction = 0;
			Board[i][j].Move = BoardB[i][j].Move;
			BoardB[i][j].Move = 0;
		}
}

void Move(int X, int Y)
{
	int Dir = Board[X][Y].Direction;

	if (Dir == 1) {
		if (BoardB[X - 1][Y].Count == 0)
			Copy(X, Y);
		else
			ForCheck(X - 1, Y);
	}
	else if (Dir == 2) {
		if (BoardB[X + 1][Y].Count == 0)
			Copy(X, Y);
		else
			ForCheck(X + 2, Y);
	}
	else if (Dir == 3) {
		if (BoardB[X][Y - 1].Count == 0)
			Copy(X, Y);
		else
			ForCheck(X, Y - 1);
	}
	else if (Dir == 4) {
		if (BoardB[X][Y + 1].Count == 0)
			Copy(X, Y);
		else
			ForCheck(X, Y + 1);
	}
}

void Copy(int X, int Y)
{
	if (Board[X][Y].Direction == 1) {
		if (BoardB[X - 1][Y].IsWall) {
			BoardB[X - 1][Y].Count = Board[X][Y].Count / 2;
			if (Board[X][Y].Direction == 1)
				BoardB[X - 1][Y].Direction = 2;
			else if (Board[X][Y].Direction == 2)
				BoardB[X - 1][Y].Direction = 1;
			else if (Board[X][Y].Direction == 3)
				BoardB[X - 1][Y].Direction = 4;
			else if (Board[X][Y].Direction == 4)
				BoardB[X - 1][Y].Direction = 3;
		}
		else {
			BoardB[X - 1][Y].Count = Board[X][Y].Count;
			BoardB[X - 1][Y].Direction = Board[X][Y].Direction;
		}
		BoardB[X - 1][Y].Move = Board[X][Y].Move + 1;
	}
	else if (Board[X][Y].Direction == 2) {
		if (BoardB[X + 1][Y].IsWall) {
			BoardB[X + 1][Y].Count = Board[X][Y].Count / 2;
			if (Board[X][Y].Direction == 1)
				BoardB[X + 1][Y].Direction = 2;
			else if (Board[X][Y].Direction == 2)
				BoardB[X + 1][Y].Direction = 1;
			else if (Board[X][Y].Direction == 3)
				BoardB[X + 1][Y].Direction = 4;
			else if (Board[X][Y].Direction == 4)
				BoardB[X + 1][Y].Direction = 3;
		}
		else {
			BoardB[X + 1][Y].Count = Board[X][Y].Count;
			BoardB[X + 1][Y].Direction = Board[X][Y].Direction;
		}
		BoardB[X + 1][Y].Move = Board[X][Y].Move + 1;
	}
	else if (Board[X][Y].Direction == 3) {
		if (BoardB[X][Y - 1].IsWall) {
			BoardB[X][Y - 1].Count = Board[X][Y].Count / 2;
			if (Board[X][Y].Direction == 1)
				BoardB[X][Y - 1].Direction = 2;
			else if (Board[X][Y].Direction == 2)
				BoardB[X][Y - 1].Direction = 1;
			else if (Board[X][Y].Direction == 3)
				BoardB[X][Y - 1].Direction = 4;
			else if (Board[X][Y].Direction == 4)
				BoardB[X][Y - 1].Direction = 3;
		}
		else {
			BoardB[X][Y - 1].Count = Board[X][Y].Count;
			BoardB[X][Y - 1].Direction = Board[X][Y].Direction;
		}
		BoardB[X][Y - 1].Move = Board[X][Y].Move + 1;
	}
	else if (Board[X][Y].Direction == 4) {
		if (BoardB[X][Y + 1].IsWall) {
			BoardB[X][Y + 1].Count = Board[X][Y].Count / 2;
			if (Board[X][Y].Direction == 1)
				BoardB[X][Y + 1].Direction = 2;
			else if (Board[X][Y].Direction == 2)
				BoardB[X][Y + 1].Direction = 1;
			else if (Board[X][Y].Direction == 3)
				BoardB[X][Y + 1].Direction = 4;
			else if (Board[X][Y].Direction == 4)
				BoardB[X][Y + 1].Direction = 3;
		}
		else {
			BoardB[X][Y + 1].Count = Board[X][Y].Count;
			BoardB[X][Y + 1].Direction = Board[X][Y].Direction;
		}
		BoardB[X][Y + 1].Move = Board[X][Y].Move + 1;
	}
}

void ForCheck(int X, int Y)
{
	int Temp[4] = { 0 };

	int max, Flag;
	max = 0;
	if (Board[X - 1][Y].Count > 0 && Board[X - 1][Y].Direction == 2) {
		Temp[0] = Board[X - 1][Y].Count;
		BoardB[X][Y].Move = Board[X - 1][Y].Move + 1;
	}
	if (max < Temp[0]) {
		max = Temp[0];
		BoardB[X][Y].Direction = Board[X - 1][Y].Direction;
	}

	if (Board[X][Y + 1].Count > 0 && Board[X][Y + 1].Direction == 3) {
		Temp[1] = Board[X][Y + 1].Count;
		BoardB[X][Y].Move = Board[X][Y + 1].Move + 1;
	}
	if (max < Temp[1]) {
		max = Temp[1];
		BoardB[X][Y].Direction = Board[X][Y + 1].Direction;
	}

	if (Board[X + 1][Y].Count > 0 && Board[X + 1][Y].Direction == 1) {
		Temp[2] = Board[X + 1][Y].Count;
		BoardB[X][Y].Move = Board[X + 1][Y].Move + 1;
	}
	if (max < Temp[2]) {
		max = Temp[2];
		BoardB[X][Y].Direction = Board[X + 1][Y].Direction;
	}

	if (Board[X][Y - 1].Count > 0 && Board[X][Y - 1].Direction == 4) {
		Temp[3] = Board[X][Y - 1].Count;
		BoardB[X][Y].Move = Board[X][Y - 1].Move + 1;
	}
	if (max < Temp[3]) {
		max = Temp[3];
		BoardB[X][Y].Direction = Board[X][Y - 1].Direction;
	}

	BoardB[X][Y].Count = 0;
	for (int i = 0; i < 4; i++)
		BoardB[X][Y].Count += Temp[i];

	if (Board[X - 1][Y].Count > 0 && Board[X - 1][Y].Direction == 2)
		Board[X - 1][Y].Count = 0;
	if (Board[X][Y + 1].Count > 0 && Board[X][Y + 1].Direction == 3)
		Board[X][Y + 1].Count = 0;
	if (Board[X + 1][Y].Count > 0 && Board[X + 1][Y].Direction == 1)
		Board[X + 1][Y].Count = 0;
	if (Board[X][Y - 1].Count > 0 && Board[X][Y - 1].Direction == 4)
		Board[X][Y - 1].Count = 0;
}