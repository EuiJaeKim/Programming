#include <iostream>
#include <algorithm>
#define ArrangeCheck(A,B) A >-1 ? A < N ? B >-1 ? B < M ? true :false : false : false : false

using namespace std;

int N, M, X, Y, K;
int Map[20][20] = { 0, };
int Order[1000] = { 0, };
int Rol[4][3] = { 0, };
int dx[5] = { 0, 0,0,-1,1 }; // 0 µ¿ ¼­ ºÏ ³²
int dy[5] = { 0, 1,-1,0,0 };

void Init();
void Move(int order);

int main()
{
	Init();

	for (int i = 0; i < K; i++) {
		Move(Order[i]);
	}

	return 0;
}

void Init()
{
	cin >> N >> M >> X >> Y >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Map[i][j];
	for (int i = 0; i < K; i++)
		cin >> Order[i];
}

void Move(int order)
{
	int* Arr[4];
	rotate(Arr, Arr + 3,Arr+ 4);
	if (order == 1) {
		if (ArrangeCheck(X + dx[order], Y + dy[order])) {
			int Temp = Rol[1][2];
			Rol[1][2] = Rol[1][1];
			Rol[1][1] = Rol[1][0];
			Rol[1][0] = Rol[3][1];
			Rol[3][1] = Temp;
			if (Map[X + dx[order]][Y + dy[order]] != 0) {
				Rol[3][1] = Map[X + dx[order]][Y + dy[order]];
				Map[X + dx[order]][Y + dy[order]] = 0;
			}
			else
				Map[X + dx[order]][Y + dy[order]] = Rol[3][1];
			printf("%d\n", Rol[1][1]);
			X += dx[order];
			Y += dy[order];
		}
		else
			return;
	}
	else if (order == 2) {
		if (ArrangeCheck(X + dx[order], Y + dy[order])) {
			int Temp = Rol[1][2];
			Rol[1][2] = Rol[3][1];
			Rol[3][1] = Rol[1][0];
			Rol[1][0] = Rol[1][1];
			Rol[1][1] = Temp;
			if (Map[X + dx[order]][Y + dy[order]] != 0) {
				Rol[3][1] = Map[X + dx[order]][Y + dy[order]];
				Map[X + dx[order]][Y + dy[order]] = 0;
			}
			else
				Map[X + dx[order]][Y + dy[order]] = Rol[3][1];
			printf("%d\n", Rol[1][1]);
			X += dx[order];
			Y += dy[order];
		}
		else
			return;
	}
	else if (order == 3) {
		if (ArrangeCheck(X + dx[order], Y + dy[order])) {
			int Temp = Rol[0][1];
			Rol[0][1] = Rol[1][1];
			Rol[1][1] = Rol[2][1];
			Rol[2][1] = Rol[3][1];
			Rol[3][1] = Temp;
			if (Map[X + dx[order]][Y + dy[order]] != 0) {
				Rol[3][1] = Map[X + dx[order]][Y + dy[order]];
				Map[X + dx[order]][Y + dy[order]] = 0;
			}
			else
				Map[X + dx[order]][Y + dy[order]] = Rol[3][1];
			printf("%d\n", Rol[1][1]);
			X += dx[order];
			Y += dy[order];
		}
		else
			return;
	}
	else if (order == 4) {
		if (ArrangeCheck(X + dx[order], Y + dy[order])) {
			int Temp = Rol[0][1];
			Rol[0][1] = Rol[3][1];
			Rol[3][1] = Rol[2][1];
			Rol[2][1] = Rol[1][1];
			Rol[1][1] = Temp;
			if (Map[X + dx[order]][Y + dy[order]] != 0) {
				Rol[3][1] = Map[X + dx[order]][Y + dy[order]];
				Map[X + dx[order]][Y + dy[order]] = 0;
			}
			else
				Map[X + dx[order]][Y + dy[order]] = Rol[3][1];
			printf("%d\n", Rol[1][1]);
			X += dx[order];
			Y += dy[order];
		}
		else
			return;
	}
}