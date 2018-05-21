#include <iostream>

using namespace std;
int N; /* 우물의 깊이 n(1≤n≤1000) */
int M; /* 장마 기간의 길이  m(1≤m≤1000) */
double Cache[1000][1000];

double Solve(int Days, int Climbed);

int main()
{
	int TC;

	cin >> TC;
	cout.setf(ios::showpoint); // 끝의 0을 표시
	cout.precision(10);
	for (int i = 0; i < TC; i++) {
		cin >> N >> M;
		for (int j = 0; j < 1000; j++)
			for (int k = 0; k < 1000; k++)
				Cache[j][k] = -1;
		cout << Solve(0, 0) << endl;
	}


	return 0;
}

double Solve(int Days, int Climbed)
{
	/* base case 마지막날일때, */
	if (Days == M) {
		/* 이날 비가 오거나 안왔을때 정상을 찍었으면 리턴. */
		if (Climbed >= N)
			return 1;
		else
			return 0;
	}

	double& Ret = Cache[Days][Climbed];

	if (Ret != -1)
		return Ret;

	Ret = (Solve(Days + 1, Climbed + 1)*0.25 + Solve(Days + 1, Climbed + 2)*0.75);

	return Ret;

}