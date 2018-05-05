#include <iostream>

using namespace std;

bool Map[10][10] = { false, };
bool IsComplete[10] = { false, };
int N; // 학생의 수 n (2 <= n <= 10) 학생들의 수는 짝수
int M; // 친구 쌍의 수 m (0 <= m <= n*(n-1)/2)
int Result;
/*
입력
입력의 첫 줄에는 테스트 케이스의 수 C (C <= 50) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 학생의 수 n (2 <= n <= 10) 과 친구 쌍의 수 m (0 <= m <= n*(n-1)/2) 이 주어집니다. 그 다음 줄에 m 개의 정수 쌍으로 서로 친구인 두 학생의 번호가 주어집니다. 번호는 모두 0 부터 n-1 사이의 정수이고, 같은 쌍은 입력에 두 번 주어지지 않습니다. 학생들의 수는 짝수입니다.

출력
각 테스트 케이스마다 한 줄에 모든 학생을 친구끼리만 짝지어줄 수 있는 방법의 수를 출력합니다.
*/

void Solve(int Cur, int Count)
{
	// 짝이 다 만들어지면 Count 변수 1증가
	if (Count == N / 2) {
		Result++;
		return;
	}

	// 짝이 다 만들어 지지 않았다면 짝을 만든다
	int i = Cur;
	while (IsComplete[i] && i < N)
		i++;

	for (int j = 0; j < N; j++) {

		if (Map[i][j] && !IsComplete[j]) {
			Map[i][j] = Map[j][i] = false;
			IsComplete[i] = IsComplete[j] = true;
			Solve(Cur + 1, Count + 1);
			Map[i][j] = Map[j][i] = true;
			IsComplete[i] = IsComplete[j] = false;
		}

	}
}
void MapInit()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Map[i][j] = false;
}

int main()
{
	int TC;


	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		int A, B;
		cin >> N;
		cin >> M;
		Result = 0;
		for (int j = 0; j < M; j++) {
			cin >> A;
			cin >> B;
			Map[A][B] = Map[B][A] = true;
		}
		Solve(0, 0);
		MapInit();

		cout << Result << endl;
	}

	return 0;
}