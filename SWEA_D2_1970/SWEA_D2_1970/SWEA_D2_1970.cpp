#include <iostream>

using namespace std;

/*

[제약 사항]

1. N은 10이상 1,000,000이하의 정수이다. (10 ≤ N ≤ 1,000,000)

2. N의 마지막 자릿수는 항상 0이다. (ex : 32850)


[입력]

가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.

각 테스트 케이스에는 N이 주어진다.


[출력]

각 줄은 '#t'로 시작하고, 다음줄에 각 돈의 종류마다 필요한 개수를 빈칸을 사이에 두고 출력한다.

*/

void Solve(int Input);

int main()
{
	int TC, N;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		cin >> N;
		printf("#%d\n", i);
		Solve(N);
	}

	return 0;
}

void Solve(int Input)
{
	int Count, Cost = 50000;

	for (int i = 1; i < 8; i++) {
		Count = 0;
		if (Input >= Cost) {
			Count = Input / Cost;
			Input -= Count * Cost;
		}
		cout << Count << " ";
		if (i % 2 == 1)
			Cost /= 5;
		else
			Cost /= 2;
	}
	cout << Input / 10 << endl;
}