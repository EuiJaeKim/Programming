#include <iostream>
#include <string>

using namespace std;

/*

[제약사항]
문자열의 길이는 항상 4의 배수로 주어진다.
그리고 문자열의 길이는 100000을 넘지 않는다.

[입력]
입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.
다음 줄부터 각 테스트 케이스가 주어진다.
테스트 케이스는 Encoding 된 상태로 주어지는 문자열이다.

[출력]
테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.
(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

*/

string Input;

void Sovle();

int main()
{
	int TC;


	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Input.clear();
		cin >> Input;
		printf("#%d ",i);
		Sovle();
		cout << endl;
	}


	return 0;
}

void Sovle()
{
	int arr[24] = { 0, };
	int* InputInt;
	int Length = Input.size();

	InputInt = new int[Length];
	/* 1. 숫자로 바꾸고 */
	for (int i = 0; i < Input.size(); i++) {
		if (Input[i] >= 'A' && Input[i] <= 'Z')
			InputInt[i] = Input[i] - 'A';
		else if (Input[i] >= 'a' && Input[i] <= 'z')
			InputInt[i] = Input[i] - 'a' + 26;
		else if (Input[i] >= '0' && Input[i] <= '9')
			InputInt[i] = Input[i] - '0' + 52;
		else if (Input[i] == '+')
			InputInt[i] = 62;
		else if (Input[i] == '/')
			InputInt[i] = 63;
	}
	/* 2. 4개씩 읽어서 24개의 배열 arr에 저장하고 8비트씩 읽어서 출력 */
	int Cur = 0;
	int BitCur;

	while (Cur < Length) {
		BitCur = 0;
		for (int i = 0; i < 4; i++) {
			if (InputInt[Cur + i] >= 32) {
				InputInt[Cur + i] -= 32;
				arr[BitCur] = 1;
			}
			else
				arr[BitCur] = 0;
			BitCur++;
			if (InputInt[Cur + i] >= 16) {
				InputInt[Cur + i] -= 16;
				arr[BitCur] = 1;
			}
			else
				arr[BitCur] = 0;
			BitCur++;
			if (InputInt[Cur + i] >= 8) {
				InputInt[Cur + i] -= 8;
				arr[BitCur] = 1;
			}
			else
				arr[BitCur] = 0;
			BitCur++;
			if (InputInt[Cur + i] >= 4) {
				InputInt[Cur + i] -= 4;
				arr[BitCur] = 1;
			}
			else
				arr[BitCur] = 0;
			BitCur++;
			if (InputInt[Cur + i] >= 2) {
				InputInt[Cur + i] -= 2;
				arr[BitCur] = 1;
			}
			else
				arr[BitCur] = 0;
			BitCur++;
			if (InputInt[Cur + i] >= 1) {
				InputInt[Cur + i] -= 1;
				arr[BitCur] = 1;
			}
			else
				arr[BitCur] = 0;
			BitCur++;
		}

		/* 문자화 */
		char Result;
		int i = 0, Temp;
		while (i < 24) {
			Result = 0;
			Temp = 128;
			for (int j = 0; j < 8; j++) {
				if (arr[i + j] == 1)
					Result += Temp;
				Temp /= 2;
			}
			i += 8;
			cout << Result;
		}
		Cur += 4;
	}
}