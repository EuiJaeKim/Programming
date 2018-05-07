#include <iostream>

using namespace std;

/*
입력
첫 줄에 테스트 케이스의 개수 C (C≤50)가 주어집니다. 각 테스트 케이스의 첫 줄에는 판자의 수 N (1≤N≤20000)이 주어집니다. 그 다음 줄에는 N개의 정수로 왼쪽부터 각 판자의 높이가 순서대로 주어집니다. 높이는 모두 10,000 이하의 음이 아닌 정수입니다.

출력
각 테스트 케이스당 정수 하나를 한 줄에 출력합니다. 이 정수는 주어진 울타리에서 잘라낼 수 있는 최대 직사각형의 크기를 나타내야 합니다.
*/
int Arr[20000] = { 0, }; // 판자의 수 N (1≤N≤20000) , 높이는 모두 10,000 이하의 음이 아닌 정수
int Length; // 판자의 수 N 

int Solve(int Left, int Right);\
int max(int a, int b) { if (a > b) return a; else return b; }
int min(int a, int b) { if (a < b) return a; else return b; }
int main()
{
	int TC;

	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		cin >> Length;
		for (int j = 0; j < Length; j++)
			cin >> Arr[j];
		cout << Solve(0, Length - 1) << endl;\
	}

	return 0;
}

int Solve(int Left, int Right)
{
	int Max, CenterMax;
	int Center = (Left + Right) / 2; // 중간 찾기

	if (Left == Right)
		return Arr[Left];

	int i = Center;
	int j = Center + 1;
	int Min = min(Arr[i], Arr[j]);
	CenterMax = Min * 2;
	Max = max(Solve(Left, i), Solve(j, Right)); // 왼쪽 오른쪽 중 큰거

	while (i > Left || j < Right) {
		if (j < Right && ( i == Left || Arr[i - 1] < Arr[j + 1])) // j > 오른쪽 끝이 Right 보단 무조건 작아야하고 그 와중에 i가 왼쪽 끝에 도달했거나? 오른쪽꺼를 추가해야하는 상황이면 추가해봄.
			Min = min(Min, Arr[++j]);
		else // 위 조건이 틀리면 왼쪽꺼를 해봐야함.
			Min = min(Min, Arr[--i]);
		CenterMax = max(CenterMax, (j - i + 1)* Min);
	}
	return max(Max, CenterMax);
}