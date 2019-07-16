#include <iostream>
#include <string>
#include <list>

using namespace std;

int N;

int main()
{
	string Input;
	char Command;
	int Size;
	cin >> Input;
	cin >> N;

	list<char> Str(Input.begin(), Input.end());
	auto Ptr = Str.end();

	for (int i = 0; i < N; i++) {
		cin >> Command;

		if (Command == 'L' || Command == 'B') {
			if (Ptr != Str.begin()) {
				Ptr--;
				if (Command == 'B') {
					Str.erase(Ptr++);
				}
			}
		}
		else if (Command == 'D') {
			if (Ptr != Str.end()) {
				Ptr++;
			}
		}
		else if (Command == 'P') {
			cin >> Command;
			Str.insert(Ptr, Command);
		}
	}
	while (Str.size()) {
		cout << Str.front();
		Str.pop_front();
	}
	return 0;
}