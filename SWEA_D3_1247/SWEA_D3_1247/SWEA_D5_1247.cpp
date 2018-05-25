#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> X,Y;
int N;

int main()
{
	int TC, Input;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cin >> N;
		X.clear();
		Y.clear();
		for (int j = 0; j < N + 2; j++) {
			cin >> Input;
			X.push_back(Input);
			cin >> Input;
			Y.push_back(Input);
		}
		
	}

	return 0;
}

