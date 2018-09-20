#include <iostream>

using namespace std;

/*
[입력]

각 테스트 케이스의 첫 번째 줄에는 문자열 계산식의 길이가 주어진다. 그 다음 줄에 문자열 계산식이 주어진다.

총 10개의 테스트 케이스가 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 답을 출력한다.
*/

int main()
{
	int Length;
	int Res;
	char Input;

	for (int i = 1; i <= 10; i++) {
		cin >> Length;
		Res = 0;
		for (int j = 0; j < Length; j++) {
			cin >> Input;
			if (Input != '+')
				Res += Input - '0';
		}
		printf("#%d %d\n",i,Res);

	}

	return 0;
}