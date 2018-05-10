#include <iostream>

using namespace std;

/*
입력
입력의 첫 줄에는 테스트 케이스의 수 C(C <= 50)가 주어집니다. 각 테스트 케이스의 첫 줄에는 삼각형의 크기 n(2 <= n <= 100)이 주어지고, 그 후 n줄에는 각 1개~n개의 숫자로 삼각형 각 가로줄에 있는 숫자가 왼쪽부터 주어집니다. 각 숫자는 1 이상 100000 이하의 자연수입니다.

출력
각 테스트 케이스마다 한 줄에 최대 경로의 숫자 합을 출력합니다.
*/
int Map[100][100];
int Visit[100][100];
int N;
int Solve(int X, int Y);

int main()
{
	int TC;

	cin >> TC;

	for (int i = 0; i < TC; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k <= j; k++) {
				cin >> Map[j][k];
				Visit[j][k] = 0;
			}
		}
		cout << Solve(0, 0) << endl;
	}
	return 0;
}

int Solve(int X, int Y)
{
	if (X == N-1)
		return Map[X][Y];


	if (Visit[X][Y] != 0)
		return Visit[X][Y];

	int A = Solve(X + 1, Y);
	int B = Solve(X + 1, Y + 1);

	if (A > B)
		return Visit[X][Y] = A + Map[X][Y];
	else
		return Visit[X][Y] = B + Map[X][Y];

}

/*
 아래의 코드에서 Sum은 최대값을 구하는데 아무 상관 없는( 단순 값 저장 ) 변수 이므로 없앨 수 있고,
 X의 리턴 시점( base case)를 배열의 범위에 넣어서 값을 저장하는게 무조건 유리함. 하나라도 더 저장해서 값 비교.
 그리고 위에서부터 내려오는 중의 값을 저장해서 비교하는것 보다는 아래부터 위로 올라올 때 값을 저장해서 비교하는게 더 유리.
# 그래도 반은 생각해냈으니 더 최적화된 코드를 짜자..
 1. 완탐 2. 중간 값저장 3. 최적화 값을 구하는데 사용하는 변수가 아니면 매개변수 없애기

int Solve(int X, int Y, int Sum)
{
if (X == N)
return Sum;


if (Visit[X][Y] > Map[X][Y] + Sum)
return 0;
Visit[X][Y] = Map[X][Y] + Sum;

int A = Solve(X + 1, Y, Visit[X][Y]);
int B = Solve(X + 1, Y + 1, Visit[X][Y]);

if (A > B)
return A;
else
return B;

}
*/