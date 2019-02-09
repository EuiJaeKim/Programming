#include <iostream>
#include <queue>

using namespace std;

char Map[10][10];
int N, M;
typedef struct Ball {
	int X;
	int Y;
	int Count;
	char Color;
}Ball;
queue<Ball> q;

void Init();
int Solve();

int main()
{
	Init();
	/*int Ans = Solve();
	if (Ans != -1)
		printf("1");
	else
		printf("0");*/
	printf("%d", Solve());
	return 0;
}

void Init()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 'B' || Map[i][j] == 'R') {
				Ball Temp;
				Temp.Color = Map[i][j];
				Temp.Count = 0;
				Temp.X = i;
				Temp.Y = j;
				q.push(Temp);
				Map[i][j] = '.';
			}
		}
	}
}

int Solve()
{
	while (!q.empty()) {
		Ball Elements[2];
		bool Flag, Check;
		int Cnt;
		int InitX[2], InitY[2];

		for (int i = 0; i < 2; i++) {
			Elements[i].Color = q.front().Color;
			Elements[i].Count = q.front().Count;
			InitX[i] = Elements[i].X = q.front().X;
			InitY[i] = Elements[i].Y = q.front().Y;
			q.pop();
		}

		// µ¿
		Flag = true;
		Check = false;
		Cnt = 0;
		while (Cnt != -1) {
			if ((Elements[0].Y + 1 != Elements[1].Y || Elements[0].X != Elements[1].X) && Map[Elements[0].X][Elements[0].Y + 1] == '.') {
				Elements[0].Y++;
				Cnt++;
			}
			else if (Elements[0].Color == 'R' && Map[Elements[0].X][Elements[0].Y + 1] == 'O') {
				Elements[0].Y++;
				Cnt++;
				Check = true;
				break;
			}
			else if (Elements[0].Color == 'B' && Map[Elements[0].X][Elements[0].Y + 1] == 'O') {
				Elements[0].Y++;
				Cnt = -1;
				break;
			}
			else if (Elements[0].Y + 1 == Elements[1].Y && Elements[0].X == Elements[1].X) {
				if (Flag) {
					while (1) {
						if (Map[Elements[1].X][Elements[1].Y + 1] == '.') {
							Elements[1].Y++;
							Cnt++;
						}
						else if (Elements[1].Color == 'R' && Map[Elements[1].X][Elements[1].Y + 1] == 'O') {
							Elements[1].Y++;
							Check = true;
							break;
						}
						else if (Elements[1].Color == 'B' && Map[Elements[1].X][Elements[1].Y + 1] == 'O') {
							Elements[1].Y++;
							Cnt = -1;
							break;
						}
						else
							break;
					}
					Flag = false;
				}
				else
					break;
			}
			else
				break;
		}

		if (Cnt != -1) {
			while (1) {
				if ((Elements[1].Y + 1 != Elements[0].Y || Elements[0].X != Elements[1].X) && Map[Elements[1].X][Elements[1].Y + 1] == '.') {
					Elements[1].Y++;
					Cnt++;
				}
				else if (Elements[1].Color == 'R' && Map[Elements[1].X][Elements[1].Y + 1] == 'O')
					return Elements[1].Count + 1;
				else if (Elements[1].Color == 'B' && Map[Elements[1].X][Elements[1].Y + 1] == 'O') {
					Cnt = -1;
					break;
				}
				else
					break;
			}
		}
		if (Check && Cnt != -1)
			return Elements[1].Count + 1;
		if (Cnt > 0 && Elements[0].Count <= 8) {
			Ball Add[2];
			for (int i = 0; i < 2; i++) {
				Add[i].Color = Elements[i].Color;
				Add[i].Count = Elements[i].Count + 1;
				Add[i].X = Elements[i].X;
				Add[i].Y = Elements[i].Y;
				q.push(Add[i]);
			}
		}
		// ¼­
		Flag = true;
		Check = false;
		Cnt = 0;
		for (int i = 0; i < 2; i++) {
			Elements[i].X = InitX[i];
			Elements[i].Y = InitY[i];
		}
		while (Cnt != -1) {
			if ((Elements[0].Y - 1 != Elements[1].Y || Elements[0].X != Elements[1].X) && Map[Elements[0].X][Elements[0].Y - 1] == '.') {
				Elements[0].Y--;
				Cnt++;
			}
			else if (Elements[0].Color == 'R' && Map[Elements[0].X][Elements[0].Y - 1] == 'O') {
				Elements[0].Y--;
				Check = true;
				break;
			}
			else if (Elements[0].Color == 'B' && Map[Elements[0].X][Elements[0].Y - 1] == 'O') {
				Elements[0].Y--;
				Cnt = -1;
				break;
			}
			else if (Elements[0].Y - 1 == Elements[1].Y && Elements[0].X == Elements[1].X) {
				if (Flag) {
					while (1) {
						if (Map[Elements[1].X][Elements[1].Y - 1] == '.') {
							Elements[1].Y--;
							Cnt++;
						}
						else if (Elements[1].Color == 'R' && Map[Elements[1].X][Elements[1].Y - 1] == 'O') {
							Check = true;
							Elements[1].Y--;
							break;
						}
						else if (Elements[1].Color == 'B' && Map[Elements[1].X][Elements[1].Y - 1] == 'O') {
							Elements[1].Y--;
							Cnt = -1;
							break;
						}
						else
							break;
					}
					Flag = false;
				}
				else
					break;
			}
			else
				break;
		}

		if (Cnt != -1) {
			while (1) {
				if (Map[Elements[1].X][Elements[1].Y - 1] == '.' && (Elements[1].X != Elements[0].X || Elements[1].Y - 1 != Elements[1].Y)) {
					Elements[1].Y--;
					Cnt++;
				}
				else if (Elements[1].Color == 'R' && Map[Elements[1].X][Elements[1].Y - 1] == 'O')
					return Elements[1].Count + 1;
				else if (Elements[1].Color == 'B' && Map[Elements[1].X][Elements[1].Y - 1] == 'O') {
					Cnt = -1;
					break;
				}
				else
					break;
			}
		}
		if (Check && Cnt != -1)
			return Elements[1].Count + 1;
		if (Cnt > 0 && Elements[0].Count <= 8) {
			Ball Add[2];
			for (int i = 0; i < 2; i++) {
				Add[i].Color = Elements[i].Color;
				Add[i].Count = Elements[i].Count + 1;
				Add[i].X = Elements[i].X;
				Add[i].Y = Elements[i].Y;
				q.push(Add[i]);
			}
		}
		// ³²
		Flag = true;
		Check = false;
		Cnt = 0;
		for (int i = 0; i < 2; i++) {
			Elements[i].X = InitX[i];
			Elements[i].Y = InitY[i];
		}
		while (Cnt != -1) {
			if ((Elements[0].Y != Elements[1].Y || Elements[0].X + 1 != Elements[1].X) && Map[Elements[0].X + 1][Elements[0].Y] == '.') {
				Elements[0].X++;
				Cnt++;
			}
			else if (Elements[0].Color == 'R' && Map[Elements[0].X + 1][Elements[0].Y] == 'O') {
				Elements[0].X++;
				Check = true;
				break;
			}
			else if (Elements[0].Color == 'B' && Map[Elements[0].X + 1][Elements[0].Y] == 'O') {
				Elements[0].X++;
				Cnt = -1;
				break;
			}
			else if (Elements[0].Y == Elements[1].Y && Elements[0].X + 1 == Elements[1].X) {
				if (Flag) {
					while (1) {
						if (Map[Elements[1].X + 1][Elements[1].Y] == '.') {
							Elements[1].X++;
							Cnt++;
						}
						else if (Elements[1].Color == 'R' && Map[Elements[1].X + 1][Elements[1].Y] == 'O') {
							Elements[1].X++;
							Check = true;
							break;
						}
						else if (Elements[1].Color == 'B' && Map[Elements[1].X + 1][Elements[1].Y] == 'O') {
							Elements[1].X++;
							Cnt = -1;
							break;
						}
						else
							break;
					}
					Flag = false;
				}
				else
					break;
			}
			else
				break;
		}

		if (Cnt != -1) {
			while (1) {
				if ((Elements[0].Y != Elements[1].Y || Elements[1].X + 1 != Elements[0].X) && Map[Elements[1].X + 1][Elements[1].Y] == '.') {
					Elements[1].X++;
					Cnt++;
				}
				else if (Elements[1].Color == 'R' && Map[Elements[1].X + 1][Elements[1].Y] == 'O')
					return Elements[1].Count + 1;
				else if (Elements[1].Color == 'B' && Map[Elements[1].X + 1][Elements[1].Y] == 'O') {
					Cnt = -1;
					break;
				}
				else
					break;
			}
		}
		if (Check && Cnt != -1)
			return Elements[1].Count + 1;
		if (Cnt > 0 && Elements[0].Count <= 8) {
			Ball Add[2];
			for (int i = 0; i < 2; i++) {
				Add[i].Color = Elements[i].Color;
				Add[i].Count = Elements[i].Count + 1;
				Add[i].X = Elements[i].X;
				Add[i].Y = Elements[i].Y;
				q.push(Add[i]);
			}
		}
		// ºÏ
		Flag = true;
		Check = false;
		Cnt = 0;
		for (int i = 0; i < 2; i++) {
			Elements[i].X = InitX[i];
			Elements[i].Y = InitY[i];
		}
		while (Cnt != -1) {
			if ((Elements[0].Y != Elements[1].Y || Elements[0].X - 1 != Elements[1].X) && Map[Elements[0].X - 1][Elements[0].Y] == '.') {
				Elements[0].X--;
				Cnt++;
			}
			else if (Elements[0].Color == 'R' && Map[Elements[0].X - 1][Elements[0].Y] == 'O') {
				Elements[0].X--;
				Check = true;
				break;
			}
			else if (Elements[0].Color == 'B' && Map[Elements[0].X - 1][Elements[0].Y] == 'O') {
				Elements[0].X--;
				Cnt = -1;
				break;
			}
			else if (Elements[0].Y == Elements[1].Y && Elements[0].X - 1 == Elements[1].X) {
				if (Flag) {
					while (1) {
						if (Map[Elements[1].X - 1][Elements[1].Y] == '.') {
							Elements[1].X--;
							Cnt++;
						}
						else if (Elements[1].Color == 'R' && Map[Elements[1].X - 1][Elements[1].Y] == 'O') {
							Elements[1].X--;
							Check = true;
							break;
						}
						else if (Elements[1].Color == 'B' && Map[Elements[1].X - 1][Elements[1].Y] == 'O') {
							Elements[1].X--;
							Cnt = -1;
							break;
						}
						else
							break;
					}
					Flag = false;
				}
				else
					break;
			}
			else
				break;
		}

		if (Cnt != -1) {
			while (1) {
				if ((Elements[0].Y != Elements[1].Y || Elements[1].X - 1 != Elements[0].X) && Map[Elements[1].X - 1][Elements[1].Y] == '.') {
					Elements[1].X--;
					Cnt++;
				}
				else if (Elements[1].Color == 'R' && Map[Elements[1].X - 1][Elements[1].Y] == 'O')
					return Elements[1].Count + 1;
				else if (Elements[1].Color == 'B' && Map[Elements[1].X - 1][Elements[1].Y] == 'O') {
					Cnt = -1;
					break;
				}
				else
					break;
			}
		}
		if (Check && Cnt != -1)
			return Elements[1].Count + 1;
		if (Cnt > 0 && Elements[0].Count <= 8) {
			Ball Add[2];
			for (int i = 0; i < 2; i++) {
				Add[i].Color = Elements[i].Color;
				Add[i].Count = Elements[i].Count + 1;
				Add[i].X = Elements[i].X;
				Add[i].Y = Elements[i].Y;
				q.push(Add[i]);
			}
		}
	}
	return -1;
}