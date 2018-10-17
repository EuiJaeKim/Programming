#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
int K;
vector<int> Map;

string Solve();

int main()
{
	int TC, Temp;

	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		cin >> N >> M >> K;
		for (int j = 0; j < N; j++) {
			cin >> Temp;
			Map.push_back(Temp);
		}
		sort(Map.begin(), Map.end());
		printf("#%d ", i);
		cout << Solve() << endl;
		Map.clear();
	}


	return 0;
}

string Solve()
{
	int Count = 0;
	int Before = -1,BeforeVal,Temp;
	for (int i = 0; i < N; i++) {
		
		if (Before != -1) {
			Temp = Map[i];
			Map[i] = Map[i] - BeforeVal + Before;
			Count += ((Map[i] / M) * K) - 1;
			Before = Map[i] % M;
			BeforeVal = Temp;
		}
		else {
			Count += ((Map[i] / M) * K) - 1;
			Before = Map[i] % M;
			BeforeVal = Map[i];
		}
		

		if (Count == -1)
			return "Impossible";
	}

	return "Possible";
}