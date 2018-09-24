#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int Map[11][11] = { 0, }; // 지도의 가로, 세로 크기는 10
int M; // 총 이동 시간 M은 20이상 100이하의 정수
int Human[2][2]; // 사용자는 총 2명이며, 사용자A는 지도의 (1, 1) 지점에서, 사용자B는 지도의 (10, 10) 지점에서 출발
int* HumanMovingA;
int* HumanMovingB;
int A; // BC의 개수 A는 1이상 8이하의 정수
int BC[8][4]; // 좌표(X, Y), 충전 범위(C), 처리량(P)
int Result;
int dx[5] = { 0,-1,0,1,0 };
int dy[5] = { 0,0,1,0,-1 };


void Init();
int Distance(int Ax, int Ay, int Bx, int By);
void HumanMove(int Time);
void Solve();


int main()
{
	int TC;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Init();
		Solve();
		printf("#%d %d\n", i, Result);
		delete(HumanMovingA);
		delete(HumanMovingB);
	}

	return 0;
}

void Init()
{
	int Temp;

	cin >> M >> A;
	Result = 0;
	Human[0][0] = Human[0][1] = 0;
	Human[1][0] = Human[1][1] = 9;
	HumanMovingA = new int[M];
	HumanMovingB = new int[M];
	for (int i = 0; i < M; i++)
		cin >> HumanMovingA[i];
	for (int i = 0; i < M; i++)
		cin >> HumanMovingB[i];
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < 4; j++)
			cin >> BC[i][j];
		Temp = BC[i][0] - 1;
		BC[i][0] = BC[i][1] - 1;
		BC[i][1] = Temp;
	}
}

int Distance(int Ax, int Ay, int Bx, int By)
{
	return (int)(abs(Ax - Bx) + abs(Ay - By));
}

void HumanMove(int Time)
{
	if (Time < M) {
		Human[0][0] += dx[HumanMovingA[Time]];
		Human[0][1] += dy[HumanMovingA[Time]];
		Human[1][0] += dx[HumanMovingB[Time]];
		Human[1][1] += dy[HumanMovingB[Time]];
	}
}

void Solve()
{
	int Time, BCChoice[2], Performance[2];

	vector<int> HumanA;
	vector<int> HumanB;

	Time = 0;
	while (Time <= M)
	{
		Performance[0] = Performance[1] = 0;
		BCChoice[0] = BCChoice[1] = -1;

		/* 연결 가능한 BC 리스트 */
		for (int i = 0; i < A; i++) {
			if (BC[i][2] >= Distance(Human[0][0], Human[0][1], BC[i][0], BC[i][1]))
				HumanA.push_back(i);
			if (BC[i][2] >= Distance(Human[1][0], Human[1][1], BC[i][0], BC[i][1]))
				HumanB.push_back(i);
		}

		/* 연결 가능한 BC중 가장 퍼포먼스가 높은 것 선택 */
		for (int i = 0; i < HumanA.size(); i++)
			if (Performance[0] < BC[HumanA[i]][3]) {
				Performance[0] = BC[HumanA[i]][3];
				BCChoice[0] = HumanA[i];
			}
		for (int i = 0; i < HumanB.size(); i++)
			if (Performance[1] < BC[HumanB[i]][3]) {
				Performance[1] = BC[HumanB[i]][3];
				BCChoice[1] = HumanB[i];
			}
		/* 서로 다른 BC를 선택했다면 더하고 끝. */
		if (BCChoice[0] != BCChoice[1])
			Result += Performance[0] + Performance[1];
		else {
			if (BCChoice[0] == -1 && BCChoice[1] == -1)
				;
			else {
				int TempAP = 0, TempA = -1, TempBP = 0, TempB = -1;
				for (int i = 0; i < HumanA.size(); i++) {
					if (HumanA[i] != BCChoice[0] && Performance[0] >= BC[HumanA[i]][3] && TempAP < BC[HumanA[i]][3]) {
						TempAP = BC[HumanA[i]][3];
						TempA = HumanA[i];
					}
				}
				for (int i = 0; i < HumanB.size(); i++) {
					if (HumanB[i] != BCChoice[1] && Performance[1] >= BC[HumanB[i]][3] && TempBP < BC[HumanB[i]][3]) {
						TempBP = BC[HumanB[i]][3];
						TempB = HumanB[i];
					}
				}
				/*
				1. A나 B 중 하나만 바꿀 수 있는경우.
				2. A , B 둘다 바꿀수 있는경우.
				3. 둘다 이전과 같은 경우.
				*/
				if (BCChoice[0] != TempA && BCChoice[1] != TempB) {
					if (TempAP > TempBP)
						Result += TempAP + Performance[1];
					else
						Result += TempBP + Performance[0];
				}
				else if (BCChoice[0] != TempA)
					Result += Performance[1] + TempAP;
				else if (BCChoice[1] != TempB)
					Result += Performance[0] + TempBP;
				else
					Result += Performance[0];
			}
		}
		HumanA.clear();
		HumanB.clear();
		HumanMove(Time++);
	}
}