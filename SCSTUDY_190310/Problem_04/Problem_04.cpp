#include <iostream>
#include <cstring>
using namespace std;

int N;
int L;
int Map[100][100];
int Result;

void Init()
{
	Result = 0;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];
}

void Search()
{
	bool Flag;
	int Build[100];
	int Temp;
	for (int i = 0; i < N; i++) {
		Flag = true;
		memset(Build, 0, sizeof(Build));
		for (int j = 1; j < N; j++) {
			Temp = Map[i][j - 1] - Map[i][j];
			if (Temp == 1) {
				if (N - j>= L) {
					int Prev;
					Prev = Map[i][j];
					for (int k = j; k - j < L; k++) {
						if (Build[k] == 0 && Map[i][k] == Prev)
							Build[k] = 1;
						else {
							Flag = false;
							break;
						}
					}
					if (!Flag)
						break;
				}
				else {
					Flag = false;
					break;
				}
			}
			else if (Temp == -1) {
				if (j >= L) {
					int Prev;
					Prev = Map[i][j-1];
					for (int k = j - 1; j - k <= L; k--) {
						if (Build[k] == 0 && Map[i][k] == Prev)
							Build[k] = 1;
						else {
							Flag = false;
							break;
						}
					}
					if (!Flag)
						break;
				}
				else {
					Flag = false;
					break;
				}
			}
			else if (Temp == 0)
				;
			else {
				Flag = false;
				break;
			}
		}
		if (Flag)
			Result++;

	}


	for (int i = 0; i < N; i++) {
		Flag = true;
		memset(Build, 0, sizeof(Build));
		for (int j = 1; j < N; j++) {
			Temp = Map[j - 1][i] - Map[j][i];
			if (Temp == 1) {
				if (N - j >= L) {
					int Prev;
					Prev = Map[j][i];
					for (int k = j; k - j < L; k++) {
						if (Build[k] == 0 && Map[k][i] == Prev)
							Build[k] = 1;
						else {
							Flag = false;
							break;
						}
					}
					if (!Flag)
						break;
				}
				else {
					Flag = false;
					break;
				}
			}
			else if (Temp == -1) {
				if (j >= L) {
					int Prev;
					Prev = Map[j - 1][i];
					for (int k = j - 1; j - k <= L; k--) {
						if (Build[k] == 0 && Map[k][i] == Prev)
							Build[k] = 1;
						else {
							Flag = false;
							break;
						}
					}
					if (!Flag)
						break;
				}
				else {
					Flag = false;
					break;
				}
			}
			else if (Temp == 0)
				;
			else {
				Flag = false;
				break;
			}
		}
		if (Flag)
			Result++;
	}

	cout << Result;
}

int main()
{
	Init();
	Search();
	return 0;
}