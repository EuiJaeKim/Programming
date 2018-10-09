#include <iostream>

using namespace std;

int N, Max;
int Ti[15];
int Pi[15];
bool IsPossible[15];

void Init();
void Solve(int Days, int Sum);

int main()
{
	Init();
	cout << Max;
	return 0;
}

void Init()
{
	cin >> N;
	Max = 0;
	for (int i = 0; i < N; i++) {
		cin >> Ti[i] >> Pi[i];
		if (Ti[i] + i > N)
			IsPossible[i] = false;
		else
			IsPossible[i] = true;
	}

	for (int i = 0; i < N; i++) {
		if (IsPossible[i])
			Solve(i + Ti[i], Pi[i]);
	}
}

void Solve(int Days, int Sum)
{
	for (int i = Days; i < N; i++) {
		if (IsPossible[i]) {
			Solve(i + Ti[i], Sum + Pi[i]);
		}
	}

	if (Max < Sum)
		Max = Sum;
}