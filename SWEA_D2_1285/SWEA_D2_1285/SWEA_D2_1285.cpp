#include <cstdio>
#include <cstdlib>

int Input[1000];
int main()
{
	int TC, Count, Min, Result;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		Min = 100001;
		Result = 0;
		scanf("%d", &Count);
		for (int j = 0; j<Count; j++) {
			scanf("%d", &Input[j]);
			if (Min >abs(Input[j]))
				Min = abs(Input[j]);
		}
		for (int j = 0; j<Count; j++) {
			if (Min == abs(Input[j]))
				Result++;
		}
		printf("#%d %d %d\n", i, Min, Result);
	}
	return 0;
}