#include <cstdio>
#include <cstring>

char Input[100];
int Count;

void Solve();

int main()
{
	int TC;

	scanf("%d", &TC);

	for (register int i = 1; i <= TC; i++) {
		scanf("%s", &Input);
		Count = 0;
		Solve();
		printf("#%d %d\n", i, Count);
	}
	return 0;
}
void Solve()
{
	int Before, Curr;

	if (Input[0] == '1') {
		Count++;
		Before = '1';
	}
	else
		Before = '0';

	for (register int i = 1; i < strlen(Input); i++) {
		Curr = Input[i];
		if (Before != Curr && (Curr == '0' || Curr == '1'))
			Count++;
		Before = Curr;
	}
}