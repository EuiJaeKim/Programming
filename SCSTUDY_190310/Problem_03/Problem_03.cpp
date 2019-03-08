#include <iostream>
#include <cstring>

using namespace std;

int Map[4][8];

int Point[4];
int K;

void Init()
{
	int Input;
	for (int i = 0; i < 4; i++) {
		cin >> Input;
		for (int j = 7; j >= 0; j--) {
			Map[i][j] = Input % 10;
			Input /= 10;
		}
		Point[i] = 0;
	}

	cin >> K;
}

void Search()
{
	int Rotate[4];
	int Num, Way;
	int Left, Right;

	for (int i = 0; i < K; i++) {
		memset(Rotate, 0, sizeof(Rotate));
		cin >> Num >> Way;
		Num -= 1;
		Rotate[Num] = Way;

		for (int j = Num; j - 1 >= 0; j--) {
			Left = Point[j] - 2;
			if (Left < 0)
				Left += 8;
			Right = Point[j - 1] + 2;
			if (Right > 7)
				Right -= 8;

			if (Map[j][Left] == Map[j-1][Right])
				break;
			else {
				if (Rotate[j] == 1)
					Rotate[j - 1] = -1;
				else
					Rotate[j - 1] = 1;
			}
		}

		for (int j = Num; j + 1 < 4; j++) {
			Right = Point[j] + 2;
			if (Right > 7)
				Right -= 8;

			Left = Point[j + 1] - 2;
			if (Left < 0)
				Left += 8;

			if (Map[j+1][Left] == Map[j][Right])
				break;
			else {
				if (Rotate[j] == 1)
					Rotate[j + 1] = -1;
				else
					Rotate[j + 1] = 1;
			}
		}
		for (int j = 0; j < 4; j++) {
			if (Rotate[j] == 1)
				Point[j]--;
			else if (Rotate[j] == -1)
				Point[j]++;

			if (Point[j] > 7)
				Point[j] -= 8;
			else if (Point[j] < 0)
				Point[j] += 8;
		}
	}

	int Result=0,Temp=1;

	for (int i = 0; i < 4; i++) {
		if (Map[i][Point[i]] == 1)
			Result += Temp;
		Temp *= 2;
	}
	cout << Result;
}


int main()
{
	Init();
	Search();
	return 0;
}