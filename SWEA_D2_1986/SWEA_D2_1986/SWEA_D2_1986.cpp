#include <iostream>

using namespace std;

/*
[제약사항]

N은 1 이상 10 이하의 정수이다. (1 ≤ N ≤ 10)


[입력]

가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.

각 테스트 케이스에는 N이 주어진다.


[출력]

각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 누적된 값을 출력한다.
*/
int Map[11] = { 0, };

void Init();

int main()
{
	int TC;
	cin >> TC;
	Init();
	for (int i = 1; i <= TC; i++) {
		printf("#%d %d\n", i, Map[i]);
	}

	return 0;
}

void Init()
{
	for (int i = 1; i < 11; i++) {
		if (i % 2 == 0)
			Map[i] = Map[i - 1] - i;
		else
			Map[i] = Map[i - 1] + i;
	}

}