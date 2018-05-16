#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
입력
첫 줄에 테스트 케이스의 개수 C (C≤20)가 주어집니다. 각 테스트 케이스는 멤버들의 성별과 팬들의 성별을 각각 나타내는 두 줄의 문자열로 구성되어 있습니다. 각 문자열은 왼쪽부터 오른쪽 순서대로 각 사람들의 성별을 나타냅니다.

M은 해당하는 사람이 남자, F는 해당하는 사람이 여자임을 나타냅니다. 멤버의 수와 팬의 수는 모두 1 이상 200,000 이하의 정수이며, 멤버의 수는 항상 팬의 수 이하입니다.

출력
각 테스트 케이스마다 한 줄에 모든 멤버들이 포옹을 하는 일이 몇 번이나 있는지 출력합니다.
*/

/*
http://devidea.tistory.com/entry/%EB%B6%84%ED%95%A0%EC%A0%95%EB%B3%B5-%EC%B9%B4%EB%9D%BC%EC%B8%A0%EB%B0%94-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
https://en.wikipedia.org/wiki/Karatsuba_algorithm
http://jaimemin.tistory.com/311
카라츠바 알고리즘(Karatsuba algorithm)으로 해결 가능하다고함.
분할정복의 대표적인 문제라하니 해봅시당
*/

/*

반으로 나눌때 if의 조건은 최소길이 이고 left right로 나눌때 left의 끝점은 Start에 (End - Start) / 2을 더해야한다.
right의 시작점 또한 Start에 (End - Start) / 2을 기준으로 시작해야한다.
잊지말장

if ((End - Start) / 2 >= HyperSenior.size()) {
LeftSum = Solve(Start, Start + (End - Start) / 2);
RightSum = Solve(Start+((End - Start) / 2), End);
}
*/

string HyperSenior;
string Fans;

int Solve(int Start, int End);
int JongManSolve();
int SolveT();
bool Check(int Start);

int main()
{
	int TC;
	char Input;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		HyperSenior.resize(200000);
		Fans.resize(200000);
		cin >> HyperSenior;
		cin >> Fans;

		cout << Solve(0, Fans.size()) << endl;
		cout << JongManSolve() << endl;
		cout << SolveT() << endl;
		HyperSenior.clear();
		Fans.clear();
	}

	return 0;
}

int JongManSolve()
{
	int N = HyperSenior.size() + Fans.size() - 1;
	int Compare = 0;
	vector<int> A(HyperSenior.size()), B(N, 0);
	for (int i = 0; i < HyperSenior.size(); i++) {
		if (HyperSenior[i] == 'M') {
			A[i] = 1;
		}

	}

	int Cur = 0;
	for (int i = 0; i < Fans.size(); i++) {
		if (Fans[i] == 'M')
		{
			for (int j = A.size() - 1; j >= 0; j--) {
				B[Cur + (A.size() - 1 - j)] += A[j];
			}
		}
		Cur++;
	}

	int Ret = 0;
	for (int i = HyperSenior.size() - 1; i < Fans.size(); i++)
		if (B[i] == 0)
			Ret++;
	A.clear();
	B.clear();
	return Ret;
}

int SolveT()
{
	/*
	1. 배열 A는 HyperSenior의 M의 갯수만큼의 길이를 가지고있고, 각 원소의 값은 HyperSenior배열에서 M의 위치.
	2. 배열 Fans를 기준으로 M이 나올때마다 서치. M의 갯수만큼만.
	*/
	vector<int> A;
	bool CountUp;
	int Count=0;

	for (int i = 0; i < HyperSenior.size(); i++) {
		if (HyperSenior[i] == 'M')
			A.push_back(i);
	}
	if (A.size() != 0) {
		for (int i = A[0]; i + HyperSenior.size() - 1 - A[0] < Fans.size(); i++) {
			if (Fans[i] == 'F') {
				CountUp = true;
				for (int j = 1; j < A.size(); j++) {
					if (Fans[i + (A[j] - A[0])] == 'M') {
						CountUp = false;
						break;
					}
				}
				if (CountUp)
					Count++;
			}
		}
	}
	else {
		Count = Fans.size() - HyperSenior.size() + 1;
	}
	A.clear();

	return Count;
}

int Solve(int Start, int End)
{
	int LeftSum, RightSum;
	LeftSum = RightSum = 0;

	if ((End - Start) / 2 >= HyperSenior.size()) {
		LeftSum = Solve(Start, Start + (End - Start) / 2);
		RightSum = Solve(Start + ((End - Start) / 2), End);
	}

	int Count = 0;
	for (int StartCur = Start + ((End - Start) / 2) - 1; StartCur >= Start; StartCur--) {
		if (StartCur + HyperSenior.size() <= End && StartCur + HyperSenior.size() > Start + (End - Start) / 2) {
			if (Check(StartCur)) {
				Count++;
			}
		}
	}
	return Count + LeftSum + RightSum;
}

bool Check(int Start)
{
	bool Res = true;
	for (int i = 0; i < HyperSenior.size(); i++) {
		if (HyperSenior[i] == 'M' && Fans[Start + i] == 'M') {
			return Res = false;
		}
	}
	return Res;
}