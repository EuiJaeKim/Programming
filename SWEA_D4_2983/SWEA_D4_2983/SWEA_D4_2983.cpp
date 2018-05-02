#include <iostream>
#include <string>
using namespace std;

int Solve(string Str);

int main()
{
	int TC, L, Res;
	string str;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cin >> L;
		cin >> str;

		Res = Solve(str);
		printf("#%d %d\n",i,Res);
	}

	return 0;
}

int Solve(string Str)
{
	string SubStr, CompareStr;

	for (int Len = Str.size() - 1; Len > 0; Len--) {
		for (int Start = 0; Start + Len < Str.size(); Start++) {
			SubStr = Str.substr(Start, Start + Len);
			CompareStr = Str.substr(Start + 1, Str.size()-1);

			if (CompareStr.find(SubStr) != string::npos)
				return SubStr.size();
		}
	}
	return 0;
}