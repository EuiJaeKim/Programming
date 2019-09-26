#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> Input;

int main(void) {
	string Str;
	int K;
	getline(cin, Str);
	for (int i = 0; i < Str.size(); i++) {
		if (Str[i] != ' ')
			Input.push_back(Str[i]);
	}
	cin >> K;
	sort(Input.begin(), Input.end());

	for (int i = 1; i < K; i++) {
		next_permutation(Input.begin(), Input.end());
	}

	for (int i = 0; i < Input.size(); i++)
		cout << Input[i];
	return 0;
}