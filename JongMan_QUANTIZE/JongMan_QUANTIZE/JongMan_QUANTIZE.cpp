#include <iostream>
#include <vector>
#include <math.h>
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
int Cache[101][11] = { 0, };
int QSum[11] = { 0, }; /* 구간합 */
int PSum[11] = { 0, }; /* 구간내 각 제곱의 합 */
int Min;

int Solve(int StartX, int GroupNum);
int MinCal(int GroupCount);
void Init();

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
		Init();
		cout << Solve(0, 0) << endl;
	}
	return 0;
}

void Init()
{
	sort(Arr.begin(), Arr.end());
	QSum[0] = Arr[0];
	PSum[0] = Arr[0] * Arr[0];
	for (int i = 1; i < N; i++) {
		QSum[i] = QSum[i - 1] + Arr[i];
		PSum[i] = PSum[i - 1] + (Arr[i] * Arr[i]);
	}
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 11; j++)
			Cache[i][j] = 0;
}

int Solve(int StartX, int GroupNum)
{


	/* 속도 문제니까
	StartX 랑 GroupNum 기준으로 Cache 만들어서 접근해
	리턴값 int로 변경하고.
	StartX 최대 100이니까 101,
	GroupNum 최대 10이니까 11.

	다시 짜.
	*/












	if (GroupNum > 0 && SelectArr[GroupNum - 1][0] + SelectArr[GroupNum - 1][1] == N)
		return MinCal(GroupNum);

	SelectArr[GroupNum][0] = StartX;
	if (GroupNum < S - 1) {
		for (int i = 1; StartX + i <= N; i++) { /* i는 Group의 크기 */
			SelectArr[GroupNum][1] = i;
			Solve(StartX + i, GroupNum + 1);
		}
	}
	else {
		SelectArr[GroupNum][1] = N - StartX;
		MinCal(GroupNum);
		Solve(N, GroupNum + 1);
	}
}

int MinCal(int GroupCount)
{
	int Sum, MiddleValue, SumTemp, PSumTemp;

	Sum = 0;
	/* SumTemp는 그룹내의 값을 다 더한 값. */
	SumTemp = QSum[SelectArr[GroupCount][0] + SelectArr[GroupCount][1] - 1] - (SelectArr[GroupCount][0] == 0 ? 0 : QSum[SelectArr[GroupCount][0] - 1]);
	PSumTemp = PSum[SelectArr[GroupCount][0] + SelectArr[GroupCount][1] - 1] - (SelectArr[GroupCount][0] == 0 ? 0 : PSum[SelectArr[GroupCount][0] - 1]);
	/* 그룹 안의 숫자들을 더해서 멤버수 만큼 나눈 값은 가장 편차가 작은 값임. 0.5 해주는건 반올림처리  */
	MiddleValue = (int)(0.5 + ((double)SumTemp / (double)SelectArr[GroupCount][1]));

	Sum += PSumTemp - (2 * MiddleValue*SumTemp) + (MiddleValue*MiddleValue*SelectArr[GroupCount][1]);
	/* 오차 제곱의 합 */

	Min = MIN(Min, Sum);
}