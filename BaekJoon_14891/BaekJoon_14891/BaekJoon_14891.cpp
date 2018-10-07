#include <iostream>

using namespace std;

int Wheel[4][8] = { 0, };
int Rotate[4] = { 0, };
int KCnt[100][2] = { 0, };
int K;

void Init();
int Solve();
void Rotaion();

int main()
{
	Init();

	cout << Solve();

	return 0;
}

void Init()
{
	char Input[10];
	for (int i = 0; i < 4; i++) {
		cin >> Input;
		for (int j = 0; j < 8; j++) {
			Wheel[i][j] = Input[j] - '0';
		}
	}
	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> KCnt[i][0] >> KCnt[i][1];
	}

}

int Solve()
{
	for (int i = 0; i < K; i++) {
		Rotate[KCnt[i][0]-1] = KCnt[i][1];
		if (KCnt[i][0] == 1) {
			if (Wheel[0][2] != Wheel[1][6]) {
				Rotate[1] = -(KCnt[i][1]);
				if (Wheel[1][2] != Wheel[2][6]) {
					Rotate[2] = -(Rotate[1]);
					if (Wheel[2][2] != Wheel[3][6])
						Rotate[3] = -(Rotate[2]);
					else
						Rotate[3] = 0;
				}
				else
					Rotate[2] = Rotate[3] = 0;
			}
			else
				Rotate[1] = Rotate[2] = Rotate[3] = 0;
		}
		else if (KCnt[i][0] == 2) {
			if (Wheel[0][2] != Wheel[1][6])
				Rotate[0] = -(KCnt[i][1]);
			else 
				Rotate[0] = 0;

			if (Wheel[1][2] != Wheel[2][6]) {
				Rotate[2] = -(KCnt[i][1]);
				if (Wheel[2][2] != Wheel[3][6])
					Rotate[3] = -(Rotate[2]);
				else
					Rotate[3] = 0;
			}
			else
				Rotate[2] = Rotate[3] = 0;
		}
		else if (KCnt[i][0] == 3) {
			if (Wheel[2][2] != Wheel[3][6])
				Rotate[3] = -(KCnt[i][1]);
			else
				Rotate[3] = 0;

			if (Wheel[1][2] != Wheel[2][6]) {
				Rotate[1] = -(KCnt[i][1]);
				if (Wheel[0][2] != Wheel[1][6])
					Rotate[0] = -(Rotate[1]);
				else
					Rotate[0] = 0;
			}
			else
				Rotate[1] = Rotate[0] = 0;
		}
		else if (KCnt[i][0] == 4) {
			if (Wheel[2][2] != Wheel[3][6]) {
				Rotate[2] = -(KCnt[i][1]);
				if (Wheel[1][2] != Wheel[2][6]) {
					Rotate[1] = -(Rotate[2]);
					if (Wheel[0][2] != Wheel[1][6])
						Rotate[0] = -(Rotate[1]);
					else
						Rotate[0] = 0;
				}
				else
					Rotate[1] = Rotate[0] = 0;
			}
			else
				Rotate[0] = Rotate[1] = Rotate[2] = 0;
		}
		Rotaion();
	}
	int Result = 0;
	if (Wheel[0][0] == 1)
		Result += 1;
	if (Wheel[1][0] == 1)
		Result += 2;
	if (Wheel[2][0] == 1)
		Result += 4;
	if (Wheel[3][0] == 1)
		Result += 8;
	return Result;
}

void Rotaion() {
	for (int i = 0; i < 4; i++) {
		if (Rotate[i] != 0) {
			int Temp;
			if (Rotate[i] == 1) { // >>
				Temp = Wheel[i][7];
				for (int j = 7; j > 0; j--) {
					Wheel[i][j] = Wheel[i][j - 1];
				}
				Wheel[i][0] = Temp;
			}
			else { // <<
				Temp = Wheel[i][0];
				for (int j = 0; j < 7; j++) {
					Wheel[i][j] = Wheel[i][j + 1];
				}
				Wheel[i][7] = Temp;
			}
		}
	}
}