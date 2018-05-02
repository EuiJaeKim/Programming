#include <cstdio>

int N;
int M;
int TwinHon, Unicon;
int Solve();

int main()
{
	int TC;


	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		scanf("%d", &N);
		scanf("%d", &M);

		Solve();
		printf("#%d %d %d\n", i, Unicon, TwinHon);
	}


	return 0;
}

int Solve()
{
	int A, B;

	A = M / 2;
	B = M - A;

	if ((A * 2) + B > N) {
		int Temp;
		Temp = (A * 2 + B) - N;
		A -= Temp;
		B += Temp;
	}
	else if ((A * 2) + B < N) {
		int Temp;
		Temp = N - (A * 2 + B);
		A += Temp;
		B -= Temp;
	}

	TwinHon = A;
	Unicon = B;
}