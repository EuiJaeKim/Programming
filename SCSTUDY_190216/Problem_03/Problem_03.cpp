#include <iostream>
#include <cstring>

using namespace std;
int N, Max;
int Map[20][20];

void Init();
void Solve(int Count, int CurMap[][20]);
void Calculation(int Dir, int(&InputMap)[20][20]);

int main()
{
	Init();
	Solve(0, Map);
	printf("%d", Max);
	return 0;
}

void Init()
{
	Max = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];
}

void Solve(int Count, int CurMap[][20])
{
	if (Count == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (Max < CurMap[i][j])
					Max = CurMap[i][j];
			}
		}
	}
	else {
		int TempMap[20][20] = { 0, };
		for (int i = 0; i < 4; i++) {
			memcpy(TempMap, CurMap, sizeof(int) * 400);
			Calculation(i, TempMap);
			Solve(Count+1, TempMap);
		}
	}
	return;
}

void Calculation(int Dir, int(&InputMap)[20][20]) {
	bool VisitMap[20][20];
	memset(VisitMap, 0, sizeof(bool) * 400);
	if (Dir == 0) {
		for (int i = N-2; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				if (InputMap[i][j] != 0) {
					for (int k = i + 1; k < N; k++) {
						if (InputMap[k][j] == 0) {
							InputMap[k][j] = InputMap[k - 1][j];
							InputMap[k - 1][j] = 0;
						}
						else if (InputMap[k][j] == InputMap[k - 1][j] && VisitMap[k][j] == false) {
							InputMap[k][j] += InputMap[k - 1][j];
							InputMap[k - 1][j] = 0;
							VisitMap[k][j] = true;
							break;
						}
						else
							break;
					}
				}
			}
		}
	}
	else if (Dir == 1) {
		for (int j = N - 2; j >= 0; j--) {
			for (int i = 0; i < N; i++) {

				if (InputMap[i][j] != 0) {
					for (int k = j + 1; k < N; k++) {
						if (InputMap[i][k] == 0) {
							InputMap[i][k] = InputMap[i][k - 1];
							InputMap[i][k - 1] = 0;
						}
						else if (InputMap[i][k] == InputMap[i][k - 1] && VisitMap[i][k] == false) {
							InputMap[i][k] += InputMap[i][k - 1];
							InputMap[i][k - 1] = 0;
							VisitMap[i][k] = true;
							break;
						}
						else
							break;
					}
				}
			}
		}
	}
	else if (Dir == 2) {
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (InputMap[i][j] != 0) {
					for (int k = i - 1; k >= 0; k--) {
						if (InputMap[k][j] == 0) {
							InputMap[k][j] = InputMap[k + 1][j];
							InputMap[k + 1][j] = 0;
						}
						else if (InputMap[k][j] == InputMap[k + 1][j] && VisitMap[k][j] == false) {
							InputMap[k][j] += InputMap[k + 1][j];
							InputMap[k + 1][j] = 0;
							VisitMap[k][j] = true;
							break;
						}
						else
							break;
					}
				}
			}
		}
	}
	else if (Dir == 3) {
		for (int j = 1; j < N; j++) {
			for (int i = 0; i < N; i++) {

				if (InputMap[i][j] != 0) {
					for (int k = j - 1; k >= 0; k--) {
						if (InputMap[i][k] == 0) {
							InputMap[i][k] = InputMap[i][k + 1];
							InputMap[i][k + 1] = 0;
						}
						else if (InputMap[i][k] == InputMap[i][k + 1] && VisitMap[i][k] == false) {
							InputMap[i][k] += InputMap[i][k + 1];
							InputMap[i][k + 1] = 0;
							VisitMap[i][k] = true;
							break;
						}
						else
							break;
					}
				}
			}
		}
	}

}