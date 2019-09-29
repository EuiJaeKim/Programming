#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map< string, int > m;
	map< int, int > M;
	int N;
	string Input;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Input;
		if (m.find(Input) != m.end()) {
			m.find(Input)->second++;
		}
		else
			m.insert(make_pair(Input, 1));
	}
	bool Flag = true;
	for (auto it = m.begin(); it != m.end(); it++) {

		if (M.find(it->second) != M.end()) {
			M.find(it->second)->second++;
		}
		else {
			if (M.size() < 2)
				M.insert(make_pair(it->second, 1));
			else
				Flag = false;
		}

		if (M.size() == 2) {
			for (auto itt = M.begin(); itt != M.end(); itt++) {
				if (itt->second == 0 || itt->second == 1)
					;
				else
					Flag = false;
			}
		}
		if (!Flag)
			break;
	}
	if (!Flag) {
		cout << "N" << endl;
		cout << N << endl;
		cout << m.size();
	}
	else {
		cout << "Y" << endl;
		for (auto itt = M.begin(); itt != M.end(); itt++) {
			if (itt->second == 0)
				Flag = false;
		}
		if (!Flag || M.size() == 1) {
			cout << N << endl;
			cout << m.size();
		}
		else {
			cout << N + 1 << endl;
			cout << m.size();
		}

	}
	return 0;
}

//3
//ant bee dragonfly
//
//Y
//3
//3
//
//4
//ant bee dragonfly ant
//
//N
//4
//3
//
//3
//ant bee ant
//
//Y
//4
//2