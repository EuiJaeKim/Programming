#include <iostream>

using namespace std;

int main(void) {

	int N, Temp;
	int S, E;
	int RetS, RetE;
	int Max = 0;
	int Input;
	cin >> N;
	Temp = 0;
	RetS = RetE = S = E = -1;
	for (int i = 0; i < N; i++) {
		cin >> Input;

		if (Input == 1) {
			E = i - 1;
			if (Max < Temp) {
				RetS = S;
				RetE = E;
				Max = Temp;
			}
			S = i;
			Temp = 0;
		}
		else if (Input == 0) {
			E++;
			Temp++;
		}
	}

	if (Temp != 0 ) {
		if (Max < Temp) {
			RetS = S;
			RetE = S-1;
			Max = Temp;
		}
	}

	if (RetE < RetS || RetS == -1) {
		cout << Max;
	}
	else {
		if (Max % 2 == 0)
			cout << Max / 2;
		else
			cout << Max / 2 + 1;
	}
	return 0;
}