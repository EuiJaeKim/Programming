#include <iostream>
#include <string>
#include <math.h>
#include <set>

using namespace std;


int N; // 숫자의 개수 8 ≤ N ≤ 28
int K; // 크기 순서 K는 생성 가능한 수의 개수보다 크게 주어지지 않는다.
string Input;

set<int> S;
set<int>::iterator iter;

void Solve();

int main()
{
	int TC;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		cin >> N >> K >> Input;
		Solve();

		iter = S.end();
		for (int j=0; j<K; j++)
			iter--;
		printf("#%d %d\n",i,*iter);
		S.clear();
		Input.clear();
	}
	return 0;
}

void Solve()
{
	int Start, Count, Temp;

	for (int i = 0; i < N / 4; i++) {
		Start = N - i;
		Temp = 0;
		Count = (N / 4) - 1;
		for (int j = 0; j < N; j++) {
			if (Start == N)
				Start = 0;
			if (Input[Start] >= 'A' && Input[Start] <= 'F')
				Temp += ((Input[Start++] - 'A' + 10) * (pow(16, Count--)));
			else
				Temp += ((Input[Start++] - '0') * (pow(16, Count--)));

			if (Count == -1) {
				S.insert(Temp);
				Temp = 0;
				Count = (N / 4) - 1;
			}
		}
	}
}