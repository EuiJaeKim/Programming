#include <cstdio>
#define ComPare(A,B) A >B ? '>' :  A==B ? '=' : '<' 
int main()
{
	int TC;
	int A, B;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		scanf("%d %d", &A, &B);
		printf("#%d %c\n", i, ComPare(A, B));
	}

	return 0;
}