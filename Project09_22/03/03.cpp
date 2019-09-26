#include <iostream>

using namespace std;

int Map[151] = { 0, };

int main(void) {
	int N, S, E;
	int Max = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S >> E;
		while (S < E) {
			Map[S]++;
			if (Map[S] > Max)
				Max = Map[S];
			S++;
		}
	}
	cout << Max;

	return 0;
}