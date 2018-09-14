#include <iostream>
#include <string>

using namespace std;

/*

[제약 사항]

각 문자열의 길이는 30이다. 마디의 최대 길이는 10이다.


[입력]

가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 길이가 30인 문자열이 주어진다.


[출력]

출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.

*/

string Input;
char Minstr[10];

int Solve();
bool Check(int Length);

int main()
{
	int TC;
	
	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		cin >> Input;

		printf("#%d %d\n",i, Solve());

		Input.clear();
	}

	return 0;
}

int Solve()
{
	Minstr[0] = Input[0];

	for (int i = 1; i < 10; i++) {
		if (Input[i] == Minstr[0])
			if (Check(i))
				return i;
		Minstr[i] = Input[i];
	}
	return 10;
}

bool Check(int Length)
{
	int Cur = 0;
	for (int i = 0; i < 30; i++) {
		if (Minstr[Cur] != Input[i])
			return false;
		Cur++;
		if (Cur == Length)
			Cur = 0;
	}
	return true;
}