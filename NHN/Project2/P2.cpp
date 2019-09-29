#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	map< int, int > m;
	int Max = 0;
	vector<int> Q, Ret;
	int N, M;
	string Input;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Input;
		if (Input.compare("enqueue") == 0) {
			cin >> M;
			if (Q.size() == 0)
				Max = 1;
			Q.push_back(M);
			if (m.find(M) != m.end()) {
				m.find(M)->second++;
				if (Max < m.find(M)->second)
					Max = m.find(M)->second;
			}
			else {
				m.insert(make_pair(M, 1));
			}

		}
		else {
			bool Flag = false;
			for (int j = 0; j < Q.size(); j++) {
				if (m.find(Q[j])->second == Max) {
					m.find(Q[j])->second--;
					Ret.push_back(Q[j]);
					Q.erase(Q.begin() + j);
					Flag = true;
				}
				if (Flag) {
					Max = 0;
					for (auto itt = m.begin(); itt != m.end(); itt++) {
						if (itt->second > Max)
							Max = itt->second;
					}
					break;
				}
			}
		}
	}

	for (int i = 0; i < Ret.size(); i++) {
		if (i + 1 < Ret.size())
			cout << Ret[i] << " ";
		else
			cout << Ret[i] << endl;
	}

	return 0;
}