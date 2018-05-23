#include <iostream>
#include <string>

using namespace std;

/*
[제약 사항]

각 단어의 길이는 3 이상 10 이하이다.


[입력]

가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에 하나의 단어가 주어진다.


[출력]

출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.
*/

string Map;

int Solve();

int main()
{
	int TC;
	cin >> TC;


	for (int i = 1; i <= TC; i++) {
		cin >> Map;
		printf("#%d %d\n",i,Solve());
		Map.clear();
	}
}

int Solve()
{
	int j = Map.size()-1;
	for (int i = 0; i < j; i++) {
		if (Map.at(i) != Map.at(j))
			return 0;
		j--;
	}
	return 1;
}