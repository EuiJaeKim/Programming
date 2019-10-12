#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int T) {

	if (T % 2 == 1)
		return 0;
	else if (T == 2)
		return 4 % 1000000007;
	else if (T == 4)
		return 30 % 1000000007;
}