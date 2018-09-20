#include <iostream>

using namespace std;

/*

[제약사항]

1. N은 2이상 30이하의 정수이다. (2 ≤ N ≤ 30)

2. 가속도의 값은 1 m/s2 혹은 2 m/s2 이다.

3. 현재 속도보다 감속할 속도가 더 클 경우, 속도는 0 m/s 가 된다.


[입력]

입력은 첫 줄에 총 테스트 케이스의 개수 T, 다음 줄부터 각 테스트 케이스가 주어진다.

테스트 케이스 첫 줄에는 Command 의 수 N이 주어지고, 둘째 줄부터, 매 줄마다 각각의 Command가 주어진다.


[출력]

테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.

(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

*/

int main()
{
	int TC;
	int N; // 입력으로 주어진 N 개의 command
	int Speed, Result, Order, Value;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		Speed = Result = 0;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> Order;
			if (Order == 0) {
				Result += Speed;
				continue;
			}
			cin >> Value;
			if (Order == 1)
				Speed += Value;
			else
				Speed -= Value;
			if (Speed < 0)
				Speed = 0;
			Result += Speed;
		}
		printf("#%d %d\n",i,Result);
	}

	return 0;
}