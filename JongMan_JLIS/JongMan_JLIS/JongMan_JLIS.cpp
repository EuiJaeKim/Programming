#include <iostream>

using namespace std;

/*
입력
입력의 첫 줄에는 테스트 케이스의 수 c ( 1 <= c <= 50 ) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 A 와 B 의 길이 n 과 m 이 주어집니다 (1 <= n,m <= 100). 다음 줄에는 n 개의 정수로 A 의 원소들이, 그 다음 줄에는 m 개의 정수로 B 의 원소들이 주어집니다. 모든 원소들은 32비트 부호 있는 정수에 저장할 수 있습니다.

출력
각 테스트 케이스마다 한 줄에, JLIS 의 길이를 출력합니다.
*/

int N, M; // A 와 B 의 길이 n 과 m 이 주어집니다 (1 <= n,m <= 100)
int Cache[101][101];
int ABArr[2][100] = { 0, };

int Solve(int AX, int BX);
long long Max(long long X, long long Y) { if (X > Y) return X; else return Y; }\

int main()
{
	int TC;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> N >> M;

		for (int j = 0; j < N; j++)
			cin >> ABArr[0][j];
		for (int j = 0; j < M; j++)
			cin >> ABArr[1][j];
		for (int j = 0; j < 101; j++)
			for (int k = 0; k < 101; k++)
				Cache[j][k] = -1; // -1 로 초기화 하는 이유는 ABArr[AX][BX]이 입력일때 AX+@ , BX+@ 의 반복문을 검사했을 경우, 큰값이 안나올때임(최대값을 찾았을때)


		cout << Solve(-1, -1) << endl; // -1, -1로 콜 하는 이유는 반복문에서 AX,BX 다음 값을 기준으로 봐야하는데 0,0을 시작으로 해야 하기때문.
	}
	return 0;
}

int Solve(int AX, int BX)
{
	int& Res = Cache[AX + 1][BX + 1]; // -1,-1일때를 대비 해서 각 +1 해주자

	if (Res != -1) // -1이 아니다? 즉 이전에 계산했었다.
		return Res;

	long long CurMax;
	long long a, b;
	if (AX == -1)// -1 이기 때문에 배열의 범위를 넘음. 그러니 걍 가장 낮은 값으로 설정
		a = 0 - 4987654321;
	else
		a = ABArr[0][AX];
	if (BX == -1)// -1 이기 때문에 배열의 범위를 넘음. 그러니 걍 가장 낮은 값으로 설정
		b = 0 - 4987654321;
	else
		b = ABArr[1][BX];

	CurMax = Max(a, b); // a랑 b 중에 큰값을 기준으로 두 순열을 비교할꺼임. ex) -4987654321 보다 큰 값이 나오면 Res = Max(Res, Solve() + 1)를 통해 최소 1이 저장됨. 
	Res = 0;
	for (int i = AX + 1; i < N; i++) {
		if (CurMax < ABArr[0][i]) {
			Res = Max(Res, Solve(i, BX) + 1);
		}
	}

	for (int i = BX + 1; i < M; i++) {
		if (CurMax < ABArr[1][i]) {
			Res = Max(Res, Solve(AX, i) + 1);
		}
	}

	return Res;
}