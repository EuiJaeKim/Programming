#include <string>
#include <vector>

using namespace std;


long long Ret;

int solution(int n, vector<int> P) {
	Ret = 0;
	int MinVal = 100001;
	for (int i = 0; i < P.size(); i++) {
		if (P[i] < MinVal) {
			MinVal = P[i];
		}
		Ret += MinVal;
	}
	return Ret;
}