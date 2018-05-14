#include <iostream>
#include <string>

using namespace std;

/*
입력
입력의 첫 줄에는 테스트 케이스의 수 C (<= 50) 가 주어집니다. 각 테스트 케이스는 8글자 이상 10000글자 이하의 숫자로 주어집니다.

출력
각 테스트 케이스마다 한 줄에 최소의 난이도를 출력합니다.
*/

int Input[10000];
int Cache[10000] = { 0, };
int N;

int Solve(int StartX);
int CheckLevel(int StartX, int Range);
int Min(int A, int B);

int main()
{
	int TC;
	string Str;
	cin >> TC;

	for (int i = 0; i < TC; i++) {
		/* 흠..... cin으로 string에 입력을 받을때 4094가 최대인거 같은데,, 이거 ide에 따라 다른건지 컴파일러에 따라 다른건지 확인은 못했는데 정황상 컴파일러 같다. */
		Str.resize(10001);
		cin >> Str;
		N = Str.size();
		for (int j = 0; j < N; j++) {
			Input[j] = Str.at(j) - '0';
			Cache[j] = 0;
		}

		cout << Solve(0) << endl;
	}

	return 0;
}

int Solve(int StartX)
{
	int Range = 3;
	int TempRet[3] = { -1,-1,-1 };


	if (StartX == N)
		return 0;
	if (StartX + Range > N)
		return -1;

	if (Cache[StartX] > 0)
		return Cache[StartX];
	Cache[StartX] = -1;


	if (StartX + Range <= N) {
		TempRet[0] = Solve(StartX + Range);

		if (TempRet[0] != -1)
			TempRet[0] += CheckLevel(StartX, Range);
	}
	if (StartX + (++Range) <= N) {
		TempRet[1] = Solve(StartX + Range);

		if (TempRet[1] != -1)
			TempRet[1] += CheckLevel(StartX, Range);
	}
	if (StartX + (++Range) <= N) {
		TempRet[2] = Solve(StartX + Range);

		if (TempRet[2] != -1)
			TempRet[2] += CheckLevel(StartX, Range);
	}
	Cache[StartX] = Min(Cache[StartX], Min(TempRet[0], Min(TempRet[1], TempRet[2])));
	return Cache[StartX];

}

int CheckLevel(int StartX, int Range)
{
	bool One, Two, Three, Four;

	One = Two = Three = Four = true;
	int Temp;
	Temp = Input[StartX + 1] - Input[StartX];
	if (!(Temp == 1 || Temp == -1))
		Two = false;

	for (int i = 0; i < Range - 1; i++) {
		if (Input[StartX + i] != Input[StartX + i + 1])
			One = false;
		if ((Temp == 1 || Temp == -1) && Input[StartX + i + 1] - Input[StartX + i] != Temp)
			Two = false;
		if (i + 2 < Range && (Input[StartX + i] != Input[StartX + i + 2]))
			Three = false;
		if (Temp != (Input[StartX + i + 1] - Input[StartX + i]))
			Four = false;
	}
	if (One)
		return 1;
	else if (Two)
		return 2;
	else if (Three)
		return 4;
	else if (Four)
		return 5;
	else
		return 10;

}

int Min(int A, int B)
{
	if (A == -1 && B == -1)
		return -1;
	else if (A == -1 && B != -1)
		return B;
	else if (A != -1 && B == -1)
		return A;
	else
		return (A > B ? B : A);
}