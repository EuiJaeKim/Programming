#include <iostream>
#include <string>

using namespace std;

int main()
{
	string Input;
	string str;
	int TC, Count;
	bool Flag;

	for (int i = 1; i <= 10; i++) {
		cin >> TC >> str >> Input;
		Count = 0;
		for (int j = 0; j < Input.size(); j++) {
			if (Input[j] == str[0]) {
				Flag = true;
				for (int k = 1; k < str.size(); k++) {
					if (Input[j + k] != str[k]) {
						Flag = false;
						break;
					}
				}
				if (Flag)
					Count++;
			}
		}
		printf("#%d %d\n",TC,Count);
		Input.clear();
		str.clear();
	}


	return 0;
}