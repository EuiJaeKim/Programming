#include <iostream>

using namespace std;

/*
입력
입력의 첫 줄에는 테스트 케이스의 수 C (1 <= C <= 50) 가 주어집니다. 그 후 각 줄에 사각형의 너비 n (1 <= n <= 100) 이 주어집니다.

출력
각 테스트 케이스마다 한 줄에 비대칭 타일링 방법의 수를 1,000,000,007 로 나눈 나머지를 출력합니다.
*/
long long Map[101] = { 0, };
int N; /* 사각형의 너비 n (1 <= n <= 100) */

void Init();
int Solve(int n);

int main()
{
	int TC;

	cin >> TC;
	Init();

	for (int i = 0; i < TC; i++) {
		cin >> N;
		cout << Solve(N) << endl;
	}
	return 0;
}

int Solve(int n)
{
	long long Temp = (Map[n] - Map[n / 2] + 1000000007) % 1000000007;

	if (n % 2 == 1)// 홀수면
		return Temp;

	Temp = (Temp - Map[(n / 2) - 1] + 1000000007);
	Temp %= 1000000007;

	return Temp;
}

void Init()
{
	Map[0] = 1;
	Map[1] = 1;
	for (int i = 2; i < 101; i++)
		Map[i] = (Map[i - 1] + Map[i - 2]) % 1000000007;
}