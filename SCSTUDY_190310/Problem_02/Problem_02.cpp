#include <iostream>
#include <math.h>
using namespace std;

int Synergy[20][20];
bool Map[10] = { 0, };
int N;
int Min;

void Init()
{
	Min = 987654321;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> Synergy[i][j];
}

void Search(int Depth, int Count)
{
	if (Depth == N / 2) {
		int Start, Link;
		Start = Link = 0;
		for (int i = 0; i < N; i++) {
			if (Map[i]) {
				for (int j = 0; j < N; j++) {
					if (Map[j])
						Start += Synergy[i][j];
				}
			}
			else {
				for (int j = 0; j < N; j++) {
					if (!Map[j])
						Link += Synergy[i][j];
				}
			}
		}
		Start = abs(Start - Link);
		if (Start < Min)
			Min = Start;
	}
	else {
		for (int i = Count; i < N; i++) {
			if (!Map[i]) {
				Map[i] = true;
				Search(Depth+1,i+1);
				Map[i] = false;
			}
		}
	}
}

int main()
{
	Init();
	Search(0,0);
	cout << Min;
	return 0;
}