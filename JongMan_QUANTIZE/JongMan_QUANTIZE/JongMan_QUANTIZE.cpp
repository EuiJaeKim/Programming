#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(A,B) A>B ? B : A

using namespace std;

/*
입력
입력의 첫 줄에는 테스트 케이스의 수 C (1 <= C <= 50) 가 주어진다. 각 테스트 케이스의 첫 줄에는 수열의 길이 N (1 <= N <= 100), 사용할 숫자의 수 S (1 <= S <= 10) 이 주어진다. 그 다음 줄에 N개의 정수로 수열의 숫자들이 주어진다. 수열의 모든 수는 1000 이하의 자연수이다.

출력
각 테스트 케이스마다, 주어진 수열을 최대 S 개의 수로 양자화할 때 오차 제곱의 합의 최소값을 출력한다.
*/

vector<int> Arr;
int N, S;/* 수열의 길이 N (1 <= N <= 100), 사용할 숫자의 수 S (1 <= S <= 10) */
int SelectArr[11][2] = { 0, }; /* 1번째 값은 시작 변수 2번째 값은 범위 */
int Min;
void Solve(int StartX, int GroupNum);
void MinCal();

int main()
{
	int TC;
	int Input;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		Min = 987654321;
		cin >> N >> S;
		Arr.clear();
		for (int j = 0; j < N; j++) {
			cin >> Input; /* 수열의 모든 수는 1000 이하의 자연수 */
			Arr.push_back(Input);
		}
		sort(Arr.begin(), Arr.end());
		Solve(0, 0);
		cout << Min << endl;
	}
	return 0;
}

void Solve(int StartX, int GroupNum)
{
	if (GroupNum == S) {
		MinCal();
		return;
	}

	SelectArr[GroupNum][0] = StartX;
	if (GroupNum < S-1) {
		for (int i = 1; N - (StartX + i) >= S - GroupNum; i++) { /* i는 Group의 크기 */
			SelectArr[GroupNum][1] = i;
			Solve(StartX + i, GroupNum + 1);
		}
	}
	else {
		SelectArr[GroupNum][1] = N - StartX-1;
		Solve(N, GroupNum + 1);
	}
}

void MinCal()
{
	int Sum, Temp;

	Sum = 0;
	for (int i = 0; i < S; i++) {
		Temp = 0;
		for (int j = 0; j < SelectArr[i][1]; j++) {
			Temp += Arr[SelectArr[i][0] + i];
		}
		Temp = (int)(0.5 + (double)(Temp / SelectArr[i][1]));
		/* 그룹 안의 숫자들을 더해서 멤버수 만큼 나눈 값은 가장 편차가 작은 값임. 0.5 해주는건 반올림처리  */
		Sum += Temp;
	}

	Min = MIN(Min, Sum);
}