#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;


int N; // 숫자의 개수 8 ≤ N ≤ 28
int K; // 크기 순서 K는 생성 가능한 수의 개수보다 크게 주어지지 않는다.
string Input;

int Solve();

int main()
{
	int TC;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		cin >> N >> K >> Input;
		printf("#%d %d\n", i, Solve());
		Input.clear();
	}
	return 0;
}

int Solve()
{
	int Start, Count, Temp, Cnt;
	int Arr[28];
	bool Flag;
	Cnt = 0;
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
				Flag = true;
				for (int k = 0; k < Cnt; k++) {
					if (Arr[k] == Temp) {
						Flag = false;
						break;
					}
				}
				if (Flag)
					Arr[Cnt++] = Temp;
				Temp = 0;
				Count = (N / 4) - 1;
			}
		}
	}
	sort(Arr, Arr + Cnt);

	return Arr[Cnt - K];
}