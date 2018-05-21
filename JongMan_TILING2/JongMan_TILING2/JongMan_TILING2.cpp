#include <iostream>

using namespace std;

/*
입력
입력의 첫 줄에는 테스트 케이스의 수(C <= 50)가 주어집니다. 그후 C줄에 각각 1개의 자연수로 n(1 <= n <= 100)이 주어집니다.

출력
각 테스트 케이스마다 한 줄에 경우의 수를 1000000007로 나눈 나머지를 출력합니다.
*/

long long Map[101];
void Init();

int main()
{
	int TC;
	int Num;
	cin >> TC;
	Init();
	for (int i = 0; i < TC; i++) {
		cin >> Num;
		cout << Map[Num]  << endl;
	}

	return 0;
}

void Init()
{
	Map[1] = 1;
	Map[2] = 2;
	for (int i = 3; i <= 100; i++)
		Map[i] = (Map[i - 1] + Map[i - 2]) % 1000000007;
}