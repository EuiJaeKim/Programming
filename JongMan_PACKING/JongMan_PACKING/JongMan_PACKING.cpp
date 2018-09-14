#include <iostream>
#include <string>
#include <vector>

using namespace std;


#define MAX(A,B) A>B ? A : B

int N; /* 물건의 수 N (1≤N≤100) */
int W; /* 용량 W (1≤W≤1000) */
vector<string> Name;
vector<int> Volume;
vector<int> Priority;
vector<string> Result;
int Cnt;
int Cache[100][1001];

void Init();
int Search(int Count, int Vol);
void BackTracking(int Count, int Vol);

int main()
{
	int TC, Max;
	string Tmp;
	cin >> TC;

	for (int i = 1; i <= TC; i++) {
		Init();
		Max = Search(0, W);
		BackTracking(0, W);
		printf("%d %d\n", Max, Cnt);
		for (int j = 0; j < Cnt; j++) {
			cout << Result[j] << endl;
		}
			
	}

	return 0;
}

void Init()
{
	int InputVal;
	string InputStr;

	cin >> N >> W;
	Name.clear();
	Volume.clear();
	Priority.clear();
	Result.clear();
	Cnt = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 1001; j++)
			Cache[i][j] = -1;

	for (int j = 0; j < N; j++) {
		cin >> InputStr;
		Name.push_back(InputStr);
		cin >> InputVal;
		Volume.push_back(InputVal);
		cin >> InputVal;
		Priority.push_back(InputVal);
	}
}

int Search(int Count, int Vol)
{
	/* Base Case */
	if (Count == N)
		return 0;

	if (Cache[Count][Vol] != -1)
		return Cache[Count][Vol];

	Cache[Count][Vol] = Search(Count + 1, Vol);

	if (Vol >= Volume[Count])
		Cache[Count][Vol] = MAX(Cache[Count][Vol], Search(Count + 1, Vol - Volume[Count]) + Priority[Count]);

	return Cache[Count][Vol];
}

void BackTracking(int Count, int Vol)
{
	if (Count == N)
		return;

	if (Search(Count, Vol) != Search(Count + 1, Vol)) {
		Result.push_back(Name[Count]);
		Cnt++;
		BackTracking(Count+1, Vol- Volume[Count]);
	}
	else if (Search(Count, Vol) == Search(Count + 1, Vol)) {
		BackTracking(Count + 1, Vol);
	}

	return;
}