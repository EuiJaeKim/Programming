#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define Max 500
#define RangeCheck(X,Y)  X < N ?  Y < M ? true : false : false
using namespace std;

int N, M;
int Map[Max][Max];
int PolyominoL[2][3] = { {0,0,1},{1,1,1} };
int PolyominoS[2][3] = { {0,1,1},{1,1,0} };
int PolyominoT[2][3] = { {0,1,0},{1,1,1} };
int Result;
int MaxValue;
vector<int> Array;

void Init();
void Solve();
int MaxReturn(int A, int B);

int main()
{
	Init();
	Solve();
	cout << Result;
	return 0;
}

void Init()
{
	Result = MaxValue = 0;
	cin >> N >> M;
	Array.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			Array.push_back(Map[i][j]);
		}
	}
	sort(Array.begin(), Array.end());
	for (int i = 0; i < 4; i++)
		MaxValue += Array[Array.size() - 1 - i];
}

void Solve()
{
	int Temp[8], OValue, IValue[2] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (RangeCheck(i + 1, j + 2)) {
				memset(Temp, 0, sizeof(Temp));
				for (int k = 0; k < 2; k++) {
					for (int L = 0; L < 3; L++) {
						Temp[0] += Map[i + k][j + L] * PolyominoL[k][L];
						Temp[1] += Map[i + k][j + L] * PolyominoL[1 - k][2 - L];
						Temp[2] += Map[i + k][j + L] * PolyominoS[k][L];
						Temp[3] += Map[i + k][j + L] * PolyominoT[k][L];
						Temp[4] += Map[i + k][j + L] * PolyominoT[1 - k][L];
						Temp[5] += Map[i + k][j + L] * PolyominoL[k][2-L];
						Temp[6] += Map[i + k][j + L] * PolyominoL[1-k][L];
						Temp[7] += Map[i + k][j + L] * PolyominoS[1-k][L];
					}
				}
				Result = MaxReturn(Result, MaxReturn(Temp[0], MaxReturn(Temp[1], MaxReturn(Temp[2], MaxReturn(Temp[3], MaxReturn( Temp[4], MaxReturn(Temp[5], MaxReturn(Temp[6], Temp[7]))))))));
				if (MaxValue == Result)
					return;
			}
			
			if (RangeCheck(i + 2, j + 1)) {
				memset(Temp, 0, sizeof(Temp));
				for (int L = 0; L < 3; L++) {
					for (int k = 0; k < 2; k++) {
						Temp[0] += Map[i + L][j + k] * PolyominoL[1-k][L];
						Temp[1] += Map[i + L][j + k] * PolyominoL[k][2 - L];
						Temp[2] += Map[i + L][j + k] * PolyominoS[k][2 - L];
						Temp[3] += Map[i + L][j + k] * PolyominoT[k][L];
						Temp[4] += Map[i + L][j + k] * PolyominoT[1 - k][L];
						Temp[5] += Map[i + L][j + k] * PolyominoL[k][L];
						Temp[6] += Map[i + L][j + k] * PolyominoL[1-k][2-L];
						Temp[7] += Map[i + L][j + k] * PolyominoS[1-k][2 - L];
					}
				}
				Result = MaxReturn(Result, MaxReturn(Temp[0], MaxReturn(Temp[1], MaxReturn(Temp[2], MaxReturn(Temp[3], MaxReturn(Temp[4], MaxReturn(Temp[5], MaxReturn(Temp[6], Temp[7]))))))));
				if (MaxValue == Result)
					return;
			}
			
			if (RangeCheck(i + 1, j + 1)) {
				OValue = 0;
				for (int k = 0; k < 2; k++) {
					for (int L = 0; L < 2; L++) {
						OValue += Map[i + k][j + L];
					}
				}
				Result = MaxReturn(Result, OValue);
				if (MaxValue == Result)
					return;
			}
			
			if (RangeCheck(i + 3, j)) {
				IValue[0] = 0;
				for (int k = 0; k < 4; k++) {
					IValue[0] += Map[i + k][j];
				}
			}
			if (RangeCheck(i, j + 3)) {
				IValue[1] = 0;
				for (int k = 0; k < 4; k++) {
					IValue[1] += Map[i][j + k];
				}
			}
			Result = MaxReturn(Result, MaxReturn(IValue[0], IValue[1]));
			if (MaxValue == Result)
				return;
		}
		
	}
}

int MaxReturn(int A, int B)
{
	if (A >= B)
		return A;
	else
		return B;
}