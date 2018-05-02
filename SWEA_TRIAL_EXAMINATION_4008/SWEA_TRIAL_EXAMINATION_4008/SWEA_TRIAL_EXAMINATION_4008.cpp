#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> Map, Oper;
int N;
int PMSD[4];
int Min, Max;

void Solve();
void Cal();

int main()
{
	int TC, Input;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Min = 1000000000;
		Max = -1000000000;
		cin >> N;
		for (int j = 0; j < 4; j++)
			cin >> PMSD[j];
		for (int j = 0; j < N; j++) {
			cin >> Input;
			Map.push_back(Input);
		}
		int Flag = 0;
		for (int j = 0; j < N - 1; j++) {
			if (PMSD[Flag] == 0) {
				while (PMSD[Flag] == 0)
					Flag++;
			}
			Oper.push_back(Flag + 1);
			PMSD[Flag]--;
		}
		Solve();
		printf("#%d %d\n", i, Max - Min);
		Map.clear();
		Oper.clear();
	}

	return 0;
}

void Solve()
{

	sort(Oper.begin(), Oper.end());
	do {
		Cal();
	} while (next_permutation(Oper.begin(), Oper.end()));

}

void Cal()
{
	int Temp = Map[0];

	for (int i = 0; i < N - 1; i++) {
		if (Oper[i] == 1)// +
			Temp += Map[i + 1];
		else if (Oper[i] == 2)//-
			Temp -= Map[i + 1];
		else if (Oper[i] == 3)//*
			Temp *= Map[i + 1];
		else if (Oper[i] == 4)// /
			Temp /= Map[i + 1];
	}
	Max = max(Max, Temp);
	Min = min(Min, Temp);
}