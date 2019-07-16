#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> PQ;

int main()
{
	int Input;
	cin >> N;

	for (int i = 0; i < N * N; i++) {
		cin >> Input;

		if (PQ.size() < N)
			PQ.push(Input);
		else if (PQ.size() == N && PQ.top() < Input) {
			PQ.pop();
			PQ.push(Input);
		}
	}
	cout << PQ.top();
	return 0;
}