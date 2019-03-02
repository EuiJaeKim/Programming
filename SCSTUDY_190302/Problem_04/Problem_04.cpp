#include <iostream>

#define N 11
using namespace std;

int Number[N];
int NumberCount;
int Operator[4];
int OperatorArray[N-1];
int Min, Max;

void Init();
void Search(int Count);

int main()
{
	Init();
	Search(0);
	cout << Max << endl << Min;

	return 0;
}

void Init()
{
	cin >> NumberCount;
	Max = -1000000001;
	Min = 1000000001;
	for (int i = 0; i < NumberCount; i++)
		cin >> Number[i];
	for (int i = 0; i < 4; i++)
		cin >> Operator[i];
}

void Search(int Count)
{
	if (Count == NumberCount - 1) {
		int Temp = Number[0], OperCount = 0;

		for (int i = 1; i < NumberCount; i++) {
			if (OperatorArray[OperCount] == 0)
				Temp += Number[i];
			else if (OperatorArray[OperCount] == 1)
				Temp -= Number[i];
			else if (OperatorArray[OperCount] == 2)
				Temp *= Number[i];
			else if (OperatorArray[OperCount] == 3)
				Temp /= Number[i];
			OperCount++;
		}
		if (Temp > Max)
			Max = Temp;
		if (Temp < Min)
			Min = Temp;
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (Operator[i] > 0) {
				Operator[i]--;
				OperatorArray[Count] = i;
				Search(Count + 1);
				Operator[i]++;
			}
		}
	}
}