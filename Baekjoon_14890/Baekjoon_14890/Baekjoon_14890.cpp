#include <iostream>
#include <cstring>

using namespace std;
int N;
int L;
int Map[100][100];
bool Check[100][100];

void Init();
int Solve();

int main()
{
	Init();
	cout << Solve();
	return 0;
}

void Init()
{
	cin >> N >> L;
	memset(Check, false, sizeof(bool) * 100 * 100);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];
}

int Solve()
{
	int Before, Cur;
	int Count = 0;

	for (int i = 0; i < N; i++) {
		Before = -10;
		Count++;
		for (int j = 0; j < N; j++) {
			Cur = Map[i][j];
			if (Before - Cur == 1) { // 앞으로 건설
				bool BuildCheck = false;
				for (int k = 0; k < L; k++) {
					if (j + k == N || Map[i][j + k] != Cur || Check[i][j + k]) {
						BuildCheck = true;
						break;
					}
				}
				if (BuildCheck) {
					Count--;
					break;
				}
				else {
					for (int k = 0; k < L; k++) {
						Check[i][j + k] = true;
					}
					j += L - 1;
				}
			}
			else if (Before - Cur == -1) { // 뒤로 건설
				bool BuildCheck = false;
				for (int k = 1; k <= L; k++) {
					if (j - k == -1 || Map[i][j - k] != Cur-1 || Check[i][j - k]) {
						BuildCheck = true;
						break;
					}
				}
				if (BuildCheck) {
					Count--;
					break;
				}
				else {
					for (int k = 1; k <= L; k++) {
						Check[i][j - k] = true;
					}
				}
			}
			else if (Before != -10 && Before != Cur) {
				Count--;
				break;
			}
			Before = Map[i][j];
		}
	}

	memset(Check, false, sizeof(bool) * 100 * 100);

	for (int j = 0; j < N; j++) {
		Before = -10;
		Count++;
		for (int i = 0; i < N; i++) {
			Cur = Map[i][j];
			if (Before - Cur == 1) { // 앞으로 건설
				bool BuildCheck = false;
				for (int k = 0; k < L; k++) {
					if (i + k == N || Map[i + k][j] != Cur || Check[i + k][j]) {
						BuildCheck = true;
						break;
					}
				}
				if (BuildCheck) {
					Count--;
					break;
				}
				else {
					for (int k = 0; k < L; k++) {
						Check[i + k][j] = true;
					}
					i += L - 1;
				}
			}
			else if (Before - Cur == -1) { // 뒤로 건설
				bool BuildCheck = false;
				for (int k = 1; k <= L; k++) {
					if (i - k == -1 || Map[i - k][j] != Cur-1 || Check[i - k][j]) {
						BuildCheck = true;
						break;
					}
				}
				if (BuildCheck) {
					Count--;
					break;
				}
				else {
					for (int k = 1; k <= L; k++) {
						Check[i - k][j] = true;
					}
				}
			}
			else if (Before != -10 && Before != Cur) {
				Count--;
				break;
			}
			Before = Map[i][j];
		}
	}

	return Count;
}