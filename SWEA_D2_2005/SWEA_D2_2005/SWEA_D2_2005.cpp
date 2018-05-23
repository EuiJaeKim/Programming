#include <iostream>

using namespace std;

/*
[제약 사항]

파스칼의 삼각형의 크기 N은 1 이상 10 이하의 정수이다. (1 ≤ N ≤ 10)


[입력]

가장 첫 줄에는 테스트 케이스의 개수 T가 주어지고, 그 아래로 각 테스트 케이스가 주어진다.

각 테스트 케이스에는 N이 주어진다.


[출력]

각 줄은 '#t'로 시작하고, 다음 줄부터 파스칼의 삼각형을 출력한다.

삼각형 각 줄의 처음 숫자가 나오기 전까지의 빈 칸은 생략하고 숫자들 사이에는 한 칸의 빈칸을 출력한다.
*/

int Map[10][10] = { 1, };

void Init();
void print(int N);

int main()
{
	int TC, Input;
	cin >> TC;
	Init();
	for (int i = 1; i <= TC; i++)
	{
		cin >> Input;
		printf("#%d\n", i);
		print(Input);
	}
	return 0;
}

void Init()
{
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			if (j-1 >= 0)
				Map[i][j] += Map[i - 1][j-1];
			if (j < i)
				Map[i][j] += Map[i - 1][j];
		}

	}
}

void print(int N)
{
	for (int i = 0; i < N; i++) {
		printf("%d", Map[i][0]);
		for (int j = 1; j <= i; j++) {
			printf(" %d", Map[i][j]);
		}
		printf("\n");
	}
}