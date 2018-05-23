#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
[제약 사항]

각 수는 0 이상 10000 이하의 정수이다.


[입력]

가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 10개의 수가 주어진다.


[출력]

출력의 각 줄은 '#t'로 시작하고, 공백을 한 칸 둔 다음 정답을 출력한다.

(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)
*/

vector<int> Map;

int main()
{
	int TC;
	int Input;
	double Temp;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Temp = 0;
		Map.clear();
		for (int j = 0; j < 10; j++) {
			cin >> Input;
			Map.push_back(Input);
		}
		sort(Map.begin(), Map.end());
		for (int j = 1; j < Map.size() - 1; j++)
			Temp += Map.at(j);
		Input = (Temp / 8) + 0.5;
		printf("#%d %d\n", i, Input);
	}

	return 0;
}