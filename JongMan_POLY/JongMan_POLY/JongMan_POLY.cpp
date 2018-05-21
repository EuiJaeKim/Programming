#include <iostream>

using namespace std;

/*
입력
입력의 첫 줄에는 테스트 케이스의 수 C (1≤C≤50)가 주어집니다. 그 후 각 줄에 폴리오미노를 구성할 정사각형의 수 n (1≤n≤100)이 주어집니다.

출력
각 테스트 케이스마다, n개의 정사각형으로 구성된 세로 단조 폴리오미노의 수를 출력합니다. 폴리오미노의 수가 10,000,000 이상일 경우 10,000,000으로 나눈 나머지를 출력합니다.
*/
long long Map[101] = { 0, };
int N; /* 정사각형의 수 n (1≤n≤100) */

void Init();

int main()
{
	int TC;

	cin >> TC;
	Init();
	for (int i = 0; i < TC; i++)
	{
		cin >> N;
		cout << Map[N] << endl;
	}

	return 0;
}

void Init()
{
	Map[0] = 0;
	Map[1] = 1;
	Map[2] = 2;
	for (int i = 3; i < 101; i++)
		Map[i] = (Map[i - 1] * 3 + Map[i - 3]) % 10000000;
}