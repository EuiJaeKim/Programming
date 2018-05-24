#include <iostream>
#include <vector>

using namespace std;

/*
[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스 별로 첫 줄에는 자연수 N(2 ≤ N ≤ 1,000,000)이 주어지고,

둘째 줄에는 각 날의 매매가를 나타내는 N개의 자연수들이 공백으로 구분되어 순서대로 주어진다.

각 날의 매매가는 10,000이하이다.


[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고, 최대 이익을 출력한다.
*/

int Max;
int MaxNum;
int Size;
vector<int> Map;
long long Solve();
int MaxChange();

int main()
{
	int TC, Input;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Max = MaxNum = 0;
		Map.clear();
		cin >> Size;

		for (int i = 0; i < Size; i++) {
			cin >> Input;
			if (Input >= Max) {
				Max = Input;
				MaxNum = i;
			}
			Map.push_back(Input);
		}
		printf("#%d %lld\n", i, Solve());
	}
	return 0;
}

long long Solve()
{
	long long Ret = 0;
	int Next, i = 0;
	do {
		while (i < MaxNum) {
			Ret += Max - Map[i++];
		}
		Next = MaxChange();
		i = MaxNum + 1;
		MaxNum = Next;
	} while (i < Size);
	return Ret;
}

int MaxChange()
{
	int NextMaxValue, NextMaxNum;
	NextMaxValue = 0;
	NextMaxNum = MaxNum;
	for (int i = 1; MaxNum + i < Map.size(); i++) {
		if (Map[MaxNum + i] >= NextMaxValue) {
			NextMaxValue = Map[MaxNum + i];
			NextMaxNum = MaxNum + i;
		}
	}
	Max = NextMaxValue;
	return NextMaxNum;
}