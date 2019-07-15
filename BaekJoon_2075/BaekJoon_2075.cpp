#include <iostream>
#include <algorithm>
using namespace std;
#define Max 3000

int N;
int Map[3000] = { 0, };

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[j];
		}
		qsort(Map, N*2, sizeof(int), compare);
	}
}

int main()
{
	init();

	cout << Map[N];
	return 0;
}