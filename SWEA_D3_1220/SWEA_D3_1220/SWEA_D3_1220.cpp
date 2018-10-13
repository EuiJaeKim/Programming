#include <iostream>

using namespace std;

int Map[100][100] = { 0, };
int N;

int Solve();

int main()
{
	for (int i = 1; i <= 10; i++) {
		cin >> N;
		for (int j = 0; j < 100; j++)
			for (int k = 0; k < 100; k++)
				cin >> Map[j][k];

		printf("#%d %d\n",i, Solve());
	}
	return 0;
}

int Solve()
{
	int Count = 0;
	int Target;
	for (int i = 0; i < 100; i++) {
		Target = 0;
		for (int j = 0; j < 100; j++) {
			if (Map[j][i] == 1 && Target == 0) {
				Target = Map[j][i];
			}
			else if (Map[j][i] == 2 && Target == 1) {
				Count++;
				Target = 0;
			}
		}
	}
	return Count;
}