#include <iostream>
#include <string>
using namespace std;

string Source;
string Target;
int Count;

void Solve();

int main()
{
	int TC;

	for (int i = 0; i < 10; i++) {
		Count = 0;
		cin >> TC >> Target >> Source;
		Solve();
		printf("#%d %d\n", TC, Count);
	}

	return 0;
}

void Solve()
{
	int Row;
	bool Correct = true;

	for (int i = 0; i <= Source.size() - Target.size(); i++) {
		if (Source[i] == Target[0]) {
			for (int j = 0; j < Target.size(); j++) {
				if (Source[i + j] != Target[j]) {
					Correct = false;
					break;
				}
			}
			if (Correct)
				Count++;
			else
				Correct = true;
		}
	}
}