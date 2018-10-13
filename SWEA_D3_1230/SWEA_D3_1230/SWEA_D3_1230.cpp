#include <iostream>
#include <vector>

using namespace std;

vector<int> Map;

void Solve(char Order);

int main()
{
	int Count;
	int Input;
	char Order;
	for (int i = 1; i <= 10; i++) {
		cin >> Count;
		Map.resize(Count);
		for (int j = 0; j < Count; j++)
			cin >> Map[j];
		cin >> Count;
		for (int j = 0; j < Count; j++) {
			cin >> Order;
			Solve(Order);
		}
		printf("#%d", i);
		for (int j = 0; j < 10; j++)
			printf(" %d", Map[j]);
		printf("\n");
		Map.clear();
	}


	return 0;
}

void Solve(char Order)
{
	int Start, Count;
	int Input;

	
	if (Order == 'I') {
		cin >> Start >> Count;
		for (int i = 0; i < Count; i++) {
			cin >> Input;
			Map.insert(Map.begin() + Start + i, Input);
		}
	}
	else if (Order == 'D') {
		cin >> Start >> Count;
		for (int i = 0; i < Count; i++) {
			Map.erase(Map.begin() + Start);
		}
	}
	else if (Order == 'A') {
		cin >> Start;
		for (int i = 0; i < Start; i++) {
			cin >> Count;
			Map.push_back(Count);
		}

	}

}