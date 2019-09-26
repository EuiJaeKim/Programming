#include <iostream>

using namespace std;

#include <cstring>

int Message[10];
int Consumer[10];

int main(void) {
	int MN, CN, Min;
	int Ret = 0;
	cin >> MN >> CN;
	memset(Consumer, 0, 10);
	for (int i = 0; i < MN; i++) {
		cin >> Message[i];
	}
	int j = 0;
	while (1) {
		Min = 101;
		for (int i = 0; i < CN; i++) {
			if (Consumer[i] == 0 && j < MN) {
				Consumer[i] = Message[j++];
			}
			if (Consumer[i] != 0 && Min >= Consumer[i])
				Min = Consumer[i];
		}
		int NMin = 101;

		Ret += Min;

		for (int i = 0; i < CN; i++) {
			Consumer[i] -= Min;
			if (Consumer[i] <= 0)
				Consumer[i] = 0;
			else if (NMin > Consumer[i]) {
				NMin = Consumer[i];
			}
		}
		Min = NMin;
		NMin = 0;
		for (int i = 0; i < CN; i++) {
			NMin += Consumer[i];
		}
		if (NMin == 0 && j == MN)
			break;
	}
	cout << Ret;
	return 0;
}