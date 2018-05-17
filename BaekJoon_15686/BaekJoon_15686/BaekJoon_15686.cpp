#include <iostream>
#include <math.h>
#define MIN(A,B) A>B ? B : A

using namespace std;

/*
입력
첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)이 주어진다.

둘째 줄부터 N개의 줄에는 도시의 정보가 주어진다.

도시의 정보는 0, 1, 2로 이루어져 있고, 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다. 집의 개수는 2N개를 넘지 않으며, 적어도 1개는 존재한다. 치킨집의 개수는 M보다 크거나 같고, 13보다 작거나 같다.

출력
첫째 줄에 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최소값을 출력한다.
*/
int N, M; /* N(2 ≤ N ≤ 50),  M(1 ≤ M ≤ 13) */
int Home[100][2] = { 0, };
int Chicken[13][2] = { 0 , };
int SelectChicken[13] = { 0, };
int HomeCount;
int ChickenCount;
int Min;

void isMin();
void Solve(int CurCount, int SelectCount);

int main()
{
	int Input;

	cin >> N >> M;
	HomeCount = ChickenCount = 0;
	Min = 987654321;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Input;
			if (Input == 1) {
				Home[HomeCount][0] = i;
				Home[HomeCount++][1] = j;
			}
			else if (Input == 2) {
				Chicken[ChickenCount][0] = i;
				Chicken[ChickenCount++][1] = j;
			}
		}
	}
	Solve(0, 0);
	cout << Min << endl;
	return 0;
}

void Solve(int CurCount, int SelectCount)
{
	/* Base Case */
	if (SelectCount == M) {
		isMin();
		return;
	}

	for (int i = CurCount; i < ChickenCount; i++) {
		SelectChicken[SelectCount] = i;
		Solve(i + 1, SelectCount + 1);
	}
}

void isMin()
{
	int Ret = 0, min;
	int Temp;
	for (int i = 0; i < HomeCount; i++) {
		min = 987654321;
		for (int j = 0; j < M; j++) {
			Temp = abs(Home[i][0] - Chicken[SelectChicken[j]][0]) + abs(Home[i][1] - Chicken[SelectChicken[j]][1]);
			min = MIN(min, Temp);
		}
		Ret += min;
	}
	Min = MIN(Ret, Min);
}