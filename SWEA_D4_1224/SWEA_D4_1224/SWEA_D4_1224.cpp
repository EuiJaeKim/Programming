#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
[입력]

각 테스트 케이스의 첫 번째 줄에는 테스트 케이스의 길이가 주어진다. 그 다음 줄에 바로 테스트 케이스가 주어진다.

총 10개의 테스트 케이스가 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 답을 출력한다.
*/

vector<char> Str;

int Priority(char Input);
void Init(int Length);
int Calculation();

int main()
{
	int Length;

	for (int i = 1; i <= 10; i++) {
		cin >> Length;
		Init(Length);
		printf("#%d %d\n", i, Calculation());
	}

	return 0;
}

void Init(int Length)
{
	char Input;
	stack<char> Data;
	stack<char> Temp;

	for (int j = 0; j < Length; j++) {
		cin >> Input;
		if (Input >= '0' && Input <= '9')
			Data.push(Input);
		else if (!Temp.empty() && Temp.top() == '(') {
			Temp.push(Input);
		}
		else if (Input == ')') {
			while (!Temp.empty()) {
				if (Temp.top() != '(') {
					Data.push(Temp.top());
					Temp.pop();
				}
				else {
					Temp.pop();
					break;
				}
			}
		}
		else {
			while (!Temp.empty()) {
				if (Temp.top() != '(' && Priority(Temp.top()) >= Priority(Input)) {
					Data.push(Temp.top());
					Temp.pop();
				}
				else
					break;
			}
			Temp.push(Input);
		}
	}
	while (!Temp.empty()) {
		Data.push(Temp.top());
		Temp.pop();
	}
	Str.clear();
	Str.resize(Data.size());
	for (int i = Data.size() - 1; i >= 0; i--) {
		Str[i] = Data.top();
		Data.pop();
	}
}

int Priority(char Input)
{
	if (Input == '+')
		return 0;
	else if (Input == '*')
		return 1;
	else if (Input == '(' || Input == ')')
		return 2;
}

int Calculation()
{
	int Result = 0;
	stack<int> Value;

	for (int i = 0; i < Str.size(); i++) {
		if (Str[i] >= '0' && Str[i] <= '9')
			Value.push(Str[i] - '0');
		else {
			Result = Value.top();
			Value.pop();
			if (Str[i] == '+')
				Result += Value.top();
			else if (Str[i] == '*')
				Result *= Value.top();
			Value.pop();
			Value.push(Result);
		}
	}
	return Value.top();
}