#include <iostream>

using namespace std;

/*
입력
입력의 첫 줄에는 테스트 케이스의 수 C (<= 50) 가 주어진다. 각 테스트 케이스의 첫 줄에는 수열에 포함된 원소의 수 N (<= 500) 이 주어진다. 그 다음 줄에 수열이 N개의 정수가 주어진다. 각 정수는 1 이상 100,000 이하의 자연수이다.

출력
각 테스트케이스마다 한 줄씩, 주어진 수열의 가장 긴 증가 부분 수열의 길이를 출력한다.
*/
int Map[500] = { 0, };
int Cache[500] = { 0, };
int N;// 수열에 포함된 원소의 수 N (<= 500)
int Max;
void Solve(int X);

int main()
{
	int TC;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> N;
		Max = 0;
		for (int j = 0; j < N; j++) {
			cin >> Map[j];
			Cache[j] = 0;
		}
		Solve(N - 1);
		cout << Max << endl;
	}
	return 0;
}

void Solve(int X)
{
	if (X < 0)
		return;

	Cache[X] = 1;

	for (int i = 0; X + i < N; i++) {
		if (Map[X + i] > Map[X]) { // 1. 순증가
			if (Cache[X + i] == 0) // 1-1. 첫방문
				Solve(X + i);
			// 1-2. 기방문
			if (Cache[X] <= Cache[X + i] + 1)
				Cache[X] = Cache[X + i] + 1;

			if (Max < Cache[X]) {
				Max = Cache[X];
				break;
			}
		}
	}
	Solve(X - 1);
}