#include <cstdio>
#include <stack>
char Input[300];
int Length;

int Solve();

int main()
{

	for (int i = 1; i <= 10; i++) {
		scanf("%d", &Length);
		scanf("%s", &Input);
		printf("#%d %d\n", i, Solve());
	}

}
int Solve()
{
	char Temp;
	std::stack<char> Tmp;

	for (int i = 0; i < Length; i++) {
		if (Input[i] == '[' || Input[i] == '{' || Input[i] == '<' || Input[i] == '(')
			Tmp.push(Input[i]);
		else {
			if (!Tmp.empty())
				Temp = Tmp.top();

			if (Temp == '[' && Input[i] == ']')
				Tmp.pop();
			else if (Temp == '{' && Input[i] == '}')
				Tmp.pop();
			else if (Temp == '<' && Input[i] == '>')
				Tmp.pop();
			else if (Temp == '(' && Input[i] == ')')
				Tmp.pop();
			else
				return 0;
		}
	}
	if (Tmp.empty())
		return 1;
	else
		return 0;
}