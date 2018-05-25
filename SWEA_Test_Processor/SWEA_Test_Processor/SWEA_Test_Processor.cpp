#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

/*
[입력]

입력의 가장 첫 줄에는 총 테스트 케이스의 개수 T가 주어지며 그 다음 줄부터 각 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 줄에는 N값이 주어지며, 다음 N줄에 걸쳐서 멕시노스의 초기 상태가 N x N 배열로 주어진다.

0은 빈 cell을 의미하며, 1은 core를 의미하고, 그 외의 숫자는 주어지지 않는다.



[출력]

각 테스트 케이스마다 '#X'를 찍고, 한 칸 띄고, 정답을 출력한다.
*/
#define MIN(A,B) A>B ? B : A
int N;
int Map[12][12]; /* 맵 */
int CoreCount; /* 코어의 갯수 */
int CoreMap[12][2]; /* 코어의 위치 */
int CoreVal[12][4]; /* 1 x-@ 북 2 y-@ 서 3 x+@ 남 4 y+@ 동 */
int CoreCur[12]; /* Core가 연결되어 있는 방향 */
int Length;
int Res;
int Result;

void Init();
void Solve(int Core, int Count, int LengthSum); /* n번째 Core, 연결된 코어 총갯수 Count, 연결된 코어의 전선길이 Length */
bool IsConnect(int CoreNum, int Loc);
void DisConnect(int CoreNum, int Loc);

int main()
{
	int TC;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cin >> N;
		Init();
		Solve(0, Res, 0);
		printf("#%d %d\n", i, Result);
	}

	return 0;
}

void Init()
{
	memset(Map, 0, sizeof(Map));
	memset(CoreMap, 0, sizeof(CoreMap));
	memset(CoreVal, 0, sizeof(CoreVal));
	memset(CoreCur, 0, sizeof(CoreCur));
	Res = 0;
	CoreCount = 0;
	Result = 987654321;
	int Input;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Input;
			if (Input == 1) {
				Map[i][j] = 1;
				if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
					Res++;
				else {
					CoreMap[CoreCount][0] = i;
					CoreMap[CoreCount++][1] = j;
				}
			}
		}
	}
	int Dis[4], A, B, C, D;
	for (int i = 0; i < CoreCount; i++) {
		A = Dis[0] = CoreMap[i][0];
		B = Dis[1] = CoreMap[i][1];
		C = Dis[2] = N - 1 - CoreMap[i][0];
		D = Dis[3] = N - 1 - CoreMap[i][1];
		sort(Dis, Dis + 4);
		for (int j = 0; j < 4; j++) {
			if (A != -1 && Dis[j] == A) {
				CoreVal[i][j] = 1;
				A = -1;
			}
			else if (B != -1 && Dis[j] == B) {
				CoreVal[i][j] = 2;
				B = -1;
			}
			else if (C != -1 && Dis[j] == C) {
				CoreVal[i][j] = 3;
				C = -1;
			}
			else if (D != -1 && Dis[j] == D) {
				CoreVal[i][j] = 4;
				D = -1;
			}
		}
	}
}

void Solve(int Core, int Count, int LengthSum)
{

	if (Core == CoreCount) {
		if (Count == Res)
			Result = MIN(Result, LengthSum);
		else if (Count > Res) {
			Result = LengthSum;
			Res = Count;
		}
		return;
	}
	// 한 코어씩 연결하면서 내려가고. 맨마지막 코어 연결하고서 Res 비교. 크거나 같다면 연결선 값 갱신.

	for (int i = 0; i < 4; i++) {
		if (IsConnect(Core, i)) {
			Solve(Core + 1, Count + 1, LengthSum + Length - 1);
			DisConnect(Core, i);
		}
	}
	Solve(Core + 1, Count, LengthSum);

	return;
}

bool IsConnect(int CoreNum, int Loc)
{
	int i = 1;

	if (CoreVal[CoreNum][Loc] == 1) {
		while (CoreMap[CoreNum][0] - i >= 0 && Map[CoreMap[CoreNum][0] - i][CoreMap[CoreNum][1]] == 0)
			i++;
		if (CoreMap[CoreNum][0] - i == -1) {
			i = 1;
			while (CoreMap[CoreNum][0] - i >= 0) {
				Map[CoreMap[CoreNum][0] - i][CoreMap[CoreNum][1]] = 2;
				i++;
			}
			Length = i;
			return true;
		}
		return false;
	}
	else if (CoreVal[CoreNum][Loc] == 2) {
		while (CoreMap[CoreNum][1] - i >= 0 && Map[CoreMap[CoreNum][0]][CoreMap[CoreNum][1] - i] == 0)
			i++;
		if (CoreMap[CoreNum][1] - i == -1) {
			i = 1;
			while (CoreMap[CoreNum][1] - i >= 0) {
				Map[CoreMap[CoreNum][0]][CoreMap[CoreNum][1] - i] = 2;
				i++;
			}
			Length = i;
			return true;
		}
		return false;
	}
	else if (CoreVal[CoreNum][Loc] == 3) {
		while (CoreMap[CoreNum][0] + i < N && Map[CoreMap[CoreNum][0] + i][CoreMap[CoreNum][1]] == 0)
			i++;
		if (CoreMap[CoreNum][0] + i == N) {
			i = 1;
			while (CoreMap[CoreNum][0] + i < N) {
				Map[CoreMap[CoreNum][0] + i][CoreMap[CoreNum][1]] = 2;
				i++;
			}
			Length = i;
			return true;
		}
		return false;
	}
	else if (CoreVal[CoreNum][Loc] == 4) {
		while (CoreMap[CoreNum][1] + i < N && Map[CoreMap[CoreNum][0]][CoreMap[CoreNum][1] + i] == 0)
			i++;
		if (CoreMap[CoreNum][1] + i == N) {
			i = 1;
			while (CoreMap[CoreNum][1] + i < N) {
				Map[CoreMap[CoreNum][0]][CoreMap[CoreNum][1] + i] = 2;
				i++;
			}
			Length = i;
			return true;
		}
		return false;
	}
	return false;
}

void DisConnect(int CoreNum, int Loc)
{
	int i = 1;

	if (CoreVal[CoreNum][Loc] == 1) {
		while (CoreMap[CoreNum][0] - i >= 0) {
			Map[CoreMap[CoreNum][0] - i][CoreMap[CoreNum][1]] = 0;
			i++;
		}
	}
	else if (CoreVal[CoreNum][Loc] == 2) {
		while (CoreMap[CoreNum][1] - i >= 0) {
			Map[CoreMap[CoreNum][0]][CoreMap[CoreNum][1] - i] = 0;
			i++;
		}
	}
	else if (CoreVal[CoreNum][Loc] == 3) {
		while (CoreMap[CoreNum][0] + i < N) {
			Map[CoreMap[CoreNum][0] + i][CoreMap[CoreNum][1]] = 0;
			i++;
		}
	}
	else if (CoreVal[CoreNum][Loc] == 4) {
		while (CoreMap[CoreNum][1] + i < N) {
			Map[CoreMap[CoreNum][0]][CoreMap[CoreNum][1] + i] = 0;
			i++;
		}
	}
}