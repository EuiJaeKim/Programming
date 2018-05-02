#include <cstdio>

int Map[50][50] = { 0, };
int Visit[50][50] = { 0, };
int N, M, R, C, L; // 맵의 세로, 가로, 맨홀의 세로, 가로, 경과시간
int Final; // 이동할 수 있는 칸의 수

void Solve(int StartX, int StartY, int Count);

int main()
{
	int T, i, j, k;

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				scanf("%d", &Map[j][k]);
			}
		}
		Final = 0;
		Solve(R, C, 1);

		printf("#%d %d\n", i, Final);
		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				Map[j][k] = 0;
				Visit[j][k] = 0;
			}
		}
	}

	return 0;
}

void Solve(int StartX, int StartY, int Count)
{
	if (StartX < 0 || StartX >N || StartY < 0 || StartY > M) // 맵 밖이면 ㅃㅃ
		return;

	if (Count <= L) {// 이동가능한 거리이고
		if (Map[StartX][StartY] > 0 && Visit[StartX][StartY] == 0) { // 터널이 있고 방문하지 않았다면
			Visit[StartX][StartY] = Count; // 방문 했다고 표시하고
			Final++; // 변수 +1 해주고
			if (Count < L) {// 한칸 더 갈 수있는지 확인.
				if (Map[StartX][StartY] == 1) {
					if (Map[StartX - 1][StartY] == 2 || Map[StartX - 1][StartY] == 5 || Map[StartX - 1][StartY] == 6 || Map[StartX - 1][StartY] == 1)
						Solve(StartX - 1, StartY, Count + 1);
					if (Map[StartX][StartY + 1] == 3 || Map[StartX][StartY + 1] == 6 || Map[StartX][StartY + 1] == 7 || Map[StartX][StartY + 1] == 1)
						Solve(StartX, StartY + 1, Count + 1);
					if (Map[StartX + 1][StartY] == 2 || Map[StartX + 1][StartY] == 4 || Map[StartX + 1][StartY] == 7 || Map[StartX + 1][StartY] == 1)
						Solve(StartX + 1, StartY, Count + 1);
					if (Map[StartX][StartY - 1] == 3 || Map[StartX][StartY - 1] == 4 || Map[StartX][StartY - 1] == 5 || Map[StartX][StartY - 1] == 1)
						Solve(StartX, StartY - 1, Count + 1);
				}
				else if (Map[StartX][StartY] == 2) {
					if (Map[StartX - 1][StartY] == 1 || Map[StartX - 1][StartY] == 2 || Map[StartX - 1][StartY] == 6 || Map[StartX - 1][StartY] == 5)
						Solve(StartX - 1, StartY, Count + 1);
					if (Map[StartX + 1][StartY] == 1 || Map[StartX + 1][StartY] == 2 || Map[StartX + 1][StartY] == 4 || Map[StartX + 1][StartY] == 7)
						Solve(StartX + 1, StartY, Count + 1);
				}
				else if (Map[StartX][StartY] == 3) {
					if (Map[StartX][StartY - 1] == 1 || Map[StartX][StartY - 1] == 3 || Map[StartX][StartY - 1] == 4 || Map[StartX][StartY - 1] == 5)
						Solve(StartX, StartY - 1, Count + 1);
					if (Map[StartX][StartY + 1] == 1 || Map[StartX][StartY + 1] == 3 || Map[StartX][StartY + 1] == 6 || Map[StartX][StartY + 1] == 7)
						Solve(StartX, StartY + 1, Count + 1);
				}
				else if (Map[StartX][StartY] == 4) {
					if (Map[StartX - 1][StartY] == 1 || Map[StartX - 1][StartY] == 2 || Map[StartX - 1][StartY] == 5 || Map[StartX - 1][StartY] == 6)
						Solve(StartX - 1, StartY, Count + 1);
					if (Map[StartX][StartY + 1] == 1 || Map[StartX][StartY + 1] == 3 || Map[StartX][StartY + 1] == 6 || Map[StartX][StartY + 1] == 7)
						Solve(StartX, StartY + 1, Count + 1);
				}
				else if (Map[StartX][StartY] == 5) {
					if (Map[StartX][StartY + 1] == 1 || Map[StartX][StartY + 1] == 3 || Map[StartX][StartY + 1] == 6 || Map[StartX][StartY + 1] == 7)
						Solve(StartX, StartY + 1, Count + 1);
					if (Map[StartX + 1][StartY] == 1 || Map[StartX + 1][StartY] == 2 || Map[StartX + 1][StartY] == 4 || Map[StartX + 1][StartY] == 7)
						Solve(StartX + 1, StartY, Count + 1);
				}
				else if (Map[StartX][StartY] == 6) {
					if (Map[StartX + 1][StartY] == 1 || Map[StartX + 1][StartY] == 2 || Map[StartX + 1][StartY] == 4 || Map[StartX + 1][StartY] == 7)
						Solve(StartX + 1, StartY, Count + 1);
					if (Map[StartX][StartY - 1] == 1 || Map[StartX][StartY - 1] == 3 || Map[StartX][StartY - 1] == 4 || Map[StartX][StartY - 1] == 5)
						Solve(StartX, StartY - 1, Count + 1);
				}
				else if (Map[StartX][StartY] == 7) {
					if (Map[StartX][StartY - 1] == 1 || Map[StartX][StartY - 1] == 3 || Map[StartX][StartY - 1] == 4 || Map[StartX][StartY - 1] == 5)
						Solve(StartX, StartY - 1, Count + 1);
					if (Map[StartX - 1][StartY] == 1 || Map[StartX - 1][StartY] == 2 || Map[StartX - 1][StartY] == 5 || Map[StartX - 1][StartY] == 6)
						Solve(StartX - 1, StartY, Count + 1);
				}
			}
			else
				return;
		}
		else if (Map[StartX][StartY] > 0 && Visit[StartX][StartY] > Count) { // 터널이 있는데 방문을 했었어 근데 나는 더갈수이쒀 글고 내가 더 유망해!
			Visit[StartX][StartY] = Count; // 카운트값 갱신!

			if (Count < L) {// 한칸 더 갈 수있는지 확인.
				if (Map[StartX][StartY] == 1) {
					if (Map[StartX - 1][StartY] == 2 || Map[StartX - 1][StartY] == 5 || Map[StartX - 1][StartY] == 6 || Map[StartX - 1][StartY] == 1)
						Solve(StartX - 1, StartY, Count + 1);
					if (Map[StartX][StartY + 1] == 3 || Map[StartX][StartY + 1] == 6 || Map[StartX][StartY + 1] == 7 || Map[StartX][StartY + 1] == 1)
						Solve(StartX, StartY + 1, Count + 1);
					if (Map[StartX + 1][StartY] == 2 || Map[StartX + 1][StartY] == 4 || Map[StartX + 1][StartY] == 7 || Map[StartX + 1][StartY] == 1)
						Solve(StartX + 1, StartY, Count + 1);
					if (Map[StartX][StartY - 1] == 3 || Map[StartX][StartY - 1] == 4 || Map[StartX][StartY - 1] == 5 || Map[StartX][StartY - 1] == 1)
						Solve(StartX, StartY - 1, Count + 1);
				}
				else if (Map[StartX][StartY] == 2) {
					if (Map[StartX - 1][StartY] == 1 || Map[StartX - 1][StartY] == 2 || Map[StartX - 1][StartY] == 6 || Map[StartX - 1][StartY] == 5)
						Solve(StartX - 1, StartY, Count + 1);
					if (Map[StartX + 1][StartY] == 1 || Map[StartX + 1][StartY] == 2 || Map[StartX + 1][StartY] == 4 || Map[StartX + 1][StartY] == 7)
						Solve(StartX + 1, StartY, Count + 1);
				}
				else if (Map[StartX][StartY] == 3) {
					if (Map[StartX][StartY - 1] == 1 || Map[StartX][StartY - 1] == 3 || Map[StartX][StartY - 1] == 4 || Map[StartX][StartY - 1] == 5)
						Solve(StartX, StartY - 1, Count + 1);
					if (Map[StartX][StartY + 1] == 1 || Map[StartX][StartY + 1] == 3 || Map[StartX][StartY + 1] == 6 || Map[StartX][StartY + 1] == 7)
						Solve(StartX, StartY + 1, Count + 1);
				}
				else if (Map[StartX][StartY] == 4) {
					if (Map[StartX - 1][StartY] == 1 || Map[StartX - 1][StartY] == 2 || Map[StartX - 1][StartY] == 5 || Map[StartX - 1][StartY] == 6)
						Solve(StartX - 1, StartY, Count + 1);
					if (Map[StartX][StartY + 1] == 1 || Map[StartX][StartY + 1] == 3 || Map[StartX][StartY + 1] == 6 || Map[StartX][StartY + 1] == 7)
						Solve(StartX, StartY + 1, Count + 1);
				}
				else if (Map[StartX][StartY] == 5) {
					if (Map[StartX][StartY + 1] == 1 || Map[StartX][StartY + 1] == 3 || Map[StartX][StartY + 1] == 6 || Map[StartX][StartY + 1] == 7)
						Solve(StartX, StartY + 1, Count + 1);
					if (Map[StartX + 1][StartY] == 1 || Map[StartX + 1][StartY] == 2 || Map[StartX + 1][StartY] == 4 || Map[StartX + 1][StartY] == 7)
						Solve(StartX + 1, StartY, Count + 1);
				}
				else if (Map[StartX][StartY] == 6) {
					if (Map[StartX + 1][StartY] == 1 || Map[StartX + 1][StartY] == 2 || Map[StartX + 1][StartY] == 4 || Map[StartX + 1][StartY] == 7)
						Solve(StartX + 1, StartY, Count + 1);
					if (Map[StartX][StartY - 1] == 1 || Map[StartX][StartY - 1] == 3 || Map[StartX][StartY - 1] == 4 || Map[StartX][StartY - 1] == 5)
						Solve(StartX, StartY - 1, Count + 1);
				}
				else if (Map[StartX][StartY] == 7) {
					if (Map[StartX][StartY - 1] == 1 || Map[StartX][StartY - 1] == 3 || Map[StartX][StartY - 1] == 4 || Map[StartX][StartY - 1] == 5)
						Solve(StartX, StartY - 1, Count + 1);
					if (Map[StartX - 1][StartY] == 1 || Map[StartX - 1][StartY] == 2 || Map[StartX - 1][StartY] == 5 || Map[StartX - 1][StartY] == 6)
						Solve(StartX - 1, StartY, Count + 1);
				}
			}
			else
				return;
		}
		else // 터널이 없다면
			return;
	}
	else
		return;
}