#include <iostream>

using namespace std;

void Init();
int** Map;
int **HashMap;

int main()
{
	int TC;
	int P, Q;
	cin >> TC;
	Init();
	for (int i = 1; i <= TC; i++) {
		cin >> P >> Q;
		printf("#%d %d\n", i, Map[HashMap[P][0] + HashMap[Q][0]+1][HashMap[P][1] + HashMap[Q][1]+1]);
	}
	delete(Map);
	delete(HashMap);
	return 0;
}

void Init()
{
	Map = new int*[500];
	for (int i = 0; i < 500; i++)
		Map[i] = new int[500];
	HashMap = new int*[67601];
	for (int i = 0; i < 67601; i++)
		HashMap[i] = new int[2];
	int X, Y;
	Y = 0;
	int Count = 1;

	while (1) {
		X = 0;
		for (int j = Y; j >= 0; j--) {
			Map[X][j] = Count;
			HashMap[Count][0] = X++;
			HashMap[Count++][1] = j;
			if (Count == 67601)
				break;
		}
		Y++;
		if (Count == 67601)
			break;
	}
}