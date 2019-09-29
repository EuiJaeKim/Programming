#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

bool* Visit;
int* FollowerCount;
int** Follower;
int* CandyCount;
queue<int> q;
int N;

void Followers();

int main()
{
	string greeting;
	char Input;
	int M, Turn;
	cin >> N;

	Visit = new bool[N];
	FollowerCount = new int[N];
	CandyCount = new int[N];

	Follower = new int* [N];
	for (int i = 0; i < N; i++)
		Follower[i] = new int[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Follower[i][j] = 0;
	//memset(Visit, 0, N);
	for (int i = 0; i < N; i++)
		Visit[i] = false;
	//memset(FollowerCount, 0, N);
	for (int i = 0; i < N; i++)
		FollowerCount[i] = 0;
	//memset(CandyCount, 0, N);
	for (int i = 0; i < N; i++)
		CandyCount[i] = 0;
	//memset(Follower, 0, N * N);

	cin.ignore();
	getline(cin, greeting);
	Turn = 0;
	for (int i = 0; i < greeting.size(); i += 2) {
		Input = greeting[i];
		if (Input == 'K') {
			Follower[Turn][FollowerCount[Turn]++] = greeting[i + 2] - '0';
			i += 2;
		}
		else if (Input == 'J') {
			if (Turn == 0) {
				CandyCount[N - 1]++;
				q.push(N - 1);
				CandyCount[Turn + 1]++;
				q.push(Turn + 1);
			}
			else if (Turn == N - 1) {
				CandyCount[0]++;
				q.push(0);
				CandyCount[Turn - 1]++;
				q.push(Turn - 1);
			}
			else {
				CandyCount[Turn + 1]++;
				q.push(Turn + 1);
				CandyCount[Turn - 1]++;
				q.push(Turn - 1);
			}
			Followers();
		}
		else if (Input == 'Q') {
			for (int j = 0; j < N; j++) {
				CandyCount[j]++;
			}
		}
		else if (Input == 'A') {
			CandyCount[Turn]++;
			q.push(Turn);
			Followers();
		}
		Turn++;
		if (Turn == N)
			Turn = 0;
	}
	for (int i = 0; i < N; i++) {
		if (i + 1 < N)
			cout << CandyCount[i] << " ";
		else
			cout << CandyCount[i];
	}

	return 0;
}

void Followers()
{
	memset(Visit, 0, N);
	int Cur;
	while (!q.empty()) {
		Cur = q.front();
		q.pop();

		for (int i = 0; i < FollowerCount[Cur]; i++) {
			if (!Visit[Follower[Cur][i]]) {
				q.push(Follower[Cur][i]);
				Visit[Follower[Cur][i]] = true;
				CandyCount[Follower[Cur][i]]++;
			}
		}
	}
}

//5
//J A Q A J A
//
//3 3 1 3 2
//
//5
//K 2 A A A A A A
//
//1 2 2 1 1
//
//5
//K 1 K 2 K 0 A Q A
//
//3 2 2 2 1