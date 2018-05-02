#include <cstdio>

int P, Q, R, S, W;// A사 : 1리터당 P원, B사 : 기본 요금이 Q원 월간 사용량이 R리터 초과량에 대해 1리터당 S원 사용하는 수도의 양이 W리터

int Solve();

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d %d %d %d %d", &P, &Q, &R, &S, &W);
		printf("#%d %d\n", i, Solve());
	}

	return 0;
}

int Solve()
{// A사 : 1리터당 P원, B사 : 기본 요금이 Q원 월간 사용량이 R리터 초과량에 대해 1리터당 S원 사용하는 수도의 양이 W리터
	int Temp;
	if (R >= W)
		Temp = Q;
	else
		Temp = Q + (W - R)*S;

	if (P*W > Temp)
		return Temp;
	else
		return P * W;
}