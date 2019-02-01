#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int MAP[10][10] = { 0, };
int HUMANCOUNT;
int HUMANLOCATION[10][2];
int STAIRLOCATION[2][2];
int STAIRLENGTH[2];
int RESULT;

void Init();
void Solve(int Num, int Arr[10]);
void CalCulation(int Arr[10]);

int main()
{
	int TC;
	int Arr[10];

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		Init();
		Solve(0, Arr);
		printf("#%d %d\n", i, RESULT+1);
	}

	return 0;
}

void Init()
{
	int STAIRCOUNT = 0;

	RESULT = 987654321;
	HUMANCOUNT = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) {
				HUMANLOCATION[HUMANCOUNT][0] = i;
				HUMANLOCATION[HUMANCOUNT++][1] = j;
			}
			else if (MAP[i][j] > 1) {
				STAIRLENGTH[STAIRCOUNT] = MAP[i][j];
				STAIRLOCATION[STAIRCOUNT][0] = i;
				STAIRLOCATION[STAIRCOUNT++][1] = j;
			}
		}
	}
}

void Solve(int Num, int Arr[10])
{
	if (Num == HUMANCOUNT)
		return;
	for (int i = Num + 1; i < HUMANCOUNT; i++)
		Arr[i] = 1;

	Arr[Num] = 0;
	CalCulation(Arr);
	Solve(Num + 1, Arr);

	Arr[Num] = 1;
	CalCulation(Arr);
	Solve(Num + 1, Arr);
}

void CalCulation(int Arr[10])
{
	int STAIR[2][10] = { 0, };
	int FirCount, SecCount;

	FirCount = SecCount = 0;

	for (int i = 0; i < HUMANCOUNT; i++) {
		if (Arr[i] == 0) {
			STAIR[Arr[i]][FirCount++] = abs(HUMANLOCATION[i][0] - STAIRLOCATION[Arr[i]][0]) + abs(HUMANLOCATION[i][1] - STAIRLOCATION[Arr[i]][1]);
		}
		else if (Arr[i] == 1) {
			STAIR[Arr[i]][SecCount++] = abs(HUMANLOCATION[i][0] - STAIRLOCATION[Arr[i]][0]) + abs(HUMANLOCATION[i][1] - STAIRLOCATION[Arr[i]][1]);
		}
	}
	sort(STAIR[0], STAIR[0] + FirCount);
	sort(STAIR[1], STAIR[1] + SecCount);

	int Down[2][3] = { 0, };
	int AT, BT;
	int AC, BC;
	int Time;
	int Clear=0;

	AT = BT = AC = BC = Time = 0;

	while (1)
	{
		Time++;
		if (Time > RESULT)
			return;

		for (int i = AC; i < FirCount; i++) {
			if (STAIR[0][i] > 0)
				STAIR[0][i]--;
		}
		for (int i = BC; i < SecCount; i++) {
			if (STAIR[1][i] > 0)
				STAIR[1][i]--;
		}
		for (int i = 0; i < 3; i++) {
			if (Down[0][i] > 0) {
				Down[0][i]--;
				if (Down[0][i] == 0) {
					AT--;
					Clear++;
				}
					
			}
		}
		for (int i = 0; i < 3; i++) {
			if (Down[1][i] > 0) {
				Down[1][i]--;
				if (Down[1][i] == 0) {
					BT--;
					Clear++;
				}
			}
		}

		if (Clear == HUMANCOUNT) {
			break;
		}

		if (AT < 3 && FirCount > AC) { // 3명 미만으로 내려가고있고 추가해야할 놈이 있을때.
			for (int i = AC; i < FirCount; i++) {
				if (STAIR[0][i] > 0) {
					AC = i;
					break;
				}
				else if (STAIR[0][i] == 0) {
					if (AT < 3) {
						for (int j = 0; j < 3; j++) {
							if (Down[0][j] == 0) {
								Down[0][j] = STAIRLENGTH[0];
								AT++;
								AC = i + 1;
								STAIR[0][i] = -1;
								break;
							}
							if (j == 2)
								AC = i;
						}
					}
					else if (AT == 3) {
						break;
					}
				}
			}
		}

		if (BT < 3 && SecCount > BC) { // 3명 미만으로 내려가고있고 추가해야할 놈이 있을때.
			for (int i = BC; i < SecCount; i++) {
				if (STAIR[1][i] > 0) {
					BC = i;
					break;
				}
				else if (STAIR[1][i] == 0) {
					if (BT < 3) {
						for (int j = 0; j < 3; j++) {
							if (Down[1][j] == 0) {
								Down[1][j] = STAIRLENGTH[1];
								BT++;
								BC = i + 1;
								STAIR[1][i] = -1;
								break;
							}
							if (j == 2)
								BC = i;
						}
					}
					else if (BT == 3) {
						break;
					}
				}
			}
		}
	}
	if (Time < RESULT)
		RESULT = Time;
}