#include <iostream>
#include <string>

using namespace std;

int** arr;
int N;
int* NumArr;
string* StrArr;

void Init() {
	int sizeX = 0, sizeY=0;
	NumArr = new int[N];
	StrArr = new string[N];
	for (int i = 0; i < N; i++) {
		cin >> NumArr[i] >> StrArr[i];
		if (sizeX < NumArr[i])
			sizeX = NumArr[i];
		sizeY += NumArr[i] * StrArr[i].size();

	}

	arr = new int* [(sizeX*2) -1];
	for (int i = 0; i < sizeX; ++i)
		arr[i] = new int[sizeY];
}

void Draw()
{
	// ½Ô ±ÍÂú
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < StrArr[i].size(); j++) {
			;
		}
	}
}

int main(void) {
	string Command;

	cin >> N >> Command;
	Init();
	Draw();

	delete[] NumArr;
	delete[] StrArr;
	return 0;
}