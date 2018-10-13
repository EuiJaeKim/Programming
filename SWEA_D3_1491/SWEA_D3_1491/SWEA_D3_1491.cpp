#include <iostream>
#include <math.h>
#define MINNUM(A,B,C) A>B ? B > C ? C : B : A > C ? C : A
using namespace std;

int N;
long long A,B,Min;

void Solve();


int main()
{
	int TC;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Min = 99987654321;
		cin >> N >> A >> B;
		Solve();
		printf("#%d %lld\n", i, Min);
	}

	return 0;
}

void Solve()
{
	long long SubMin, SubSubMin;
	int C, R;

	for (int i = 1; i <= N; i++) {
		R = i;
		C = N / i;
		if (R > C)
			break;

		for (int j = C; j > 0; j--) {
			SubMin = (A * abs(R - j)) + (B * (N - R * j));
			SubSubMin = (A * abs(j - R)) + (B * (N - j * R));
			Min = MINNUM(Min, SubMin, SubSubMin);
			if (Min == 0)
				return;
		}
	}
}