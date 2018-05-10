#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
입력
입력의 첫 줄에는 테스트 케이스의 수 C (1 <= C <= 10) 가 주어진다. 각 테스트 케이스의 첫 줄에는 와일드카드 문자열 W 가 주어지며, 그 다음 줄에는 파일명의 수 N (1 <= N <= 50) 이 주어진다. 그 후 N 줄에 하나씩 각 파일명이 주어진다. 파일명은 공백 없이 알파벳 대소문자와 숫자만으로 이루어져 있으며, 와일드카드는 그 외에 * 와 ? 를 가질 수 있다. 모든 문자열의 길이는 1 이상 100 이하이다.

출력
각 테스트 케이스마다 주어진 와일드카드에 매치되는 파일들의 이름을 한 줄에 하나씩 아스키 코드 순서(숫자, 대문자, 소문자 순)대로 출력한다.
*/

string W; // 와일드카드 문자열 W
string S;
bool Visit[100][100]; // 연속된 '*'를 컷트하기 위한 
bool Solve(int w, int s);

int main()
{
	int TC;
	int N; // 파일명의 수 N (1 <= N <= 50)
	vector<string> Res;

	cin >> TC;

	for (int i = 0; i < TC; i++) {
		cin >> W;
		cin >> N;
		for (int j = 0; j < N; j++) {
			for (int j = 0; j < 100; j++)
				for (int k = 0; k < 100; k++)
					Visit[j][k] = false;
			cin >> S;
			if (Solve(0, 0))
				Res.push_back(S);
		}
		if (Res.size() != 0) {
			sort(Res.begin(), Res.end());
			for (int j = 0; j < Res.size(); j++)
				cout << Res.at(j) << endl;
		}

		Res.clear();
	}

	return 0;
}

bool Solve(int w, int s)
{
	// '*'가 연속될때 컷트 해야함.. 안그럼 연산좀 많을듯
	if (Visit[w][s])
		return false;
	Visit[w][s] = true;
		// w, s가 문자열 길이보다 작아야하고.. W[w] 랑 S[s]랑 같거나 W[w]가 ? 여야함.
	while (W.size() > w && S.size() > s && (W[w] == '?' || W[w] == S[s])) {
		w++;
		s++;
	}
	// 1. 끝에 도달했니?
	if (W.size() == w && S.size() == s)
		return true;
	// 2. 끝이 아니면 W[w]가 '*' 겠지?
	if (W[w] == '*') {
		// s 뒤로 쭉쭉 가
		while (S.size() >= s) {
			if (Solve(w + 1, s))
				return true;
			s++;
		}
	}
	return false;
}