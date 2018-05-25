#include <iostream>
#include <vector>

using namespace std;

/*
[입력]
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에 즐거운 날의 수 N이 주어진다. (2 ≤ N ≤ 5000)

각 테스트 케이스의 두 번째 줄부터 N개의 줄에 걸쳐 즐거운 날의 정보가 오름차순으로 정렬되어 주어진다.

시작하는 날은 항상 1일이고, 마지막 날은 109보다 작은 값이다.

[출력]
각 테스트 케이스마다 항구에 들렀던 배의 최소 수를 출력한다.
*/
int N;
vector<int> Map;

int main()
{
	int TC;
	int Input;
	bool IsExist;
	int Res;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Map.clear();
		cin >> N;
		cin >> Input;
		Res = 0;
		IsExist = false;
		for (int j = 1; j < N; j++) {
			cin >> Input;
			for (int k = 0; k < Map.size(); k++) {
				if ((Input-1)%Map.at(k) == 0) {
					IsExist = true;
					break;
				}
			}
			if (!IsExist) {
				Map.push_back(Input-1);
				Res++;
			}
			else
				IsExist = false;
		}
		printf("#%d %d\n", i,Res);
	}

	return 0;
}