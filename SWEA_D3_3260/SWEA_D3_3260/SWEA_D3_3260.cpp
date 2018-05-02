#include <cstdio>
#include <string.h>

char* A;
char* B;

int Flag;
void Solve();

int main()
{
	int TC;
	char Input[100];
	char InputT[100];
	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {
		Flag = 0;
		scanf("%s", &Input);
		A = strtok(Input, " ");
		scanf("%s", &InputT);
		B = strtok(InputT, " ");
		Solve();

		if (Flag == 1)
			printf("#%d 1%s\n", i, A);
		else
			printf("#%d %s\n", i, A);
	}

	return 0;
}

void Solve()
{
	int i = 0;
	int ALen, BLen;
	ALen = strlen(A) - 1;
	BLen = strlen(B) - 1;
	char* Temp;
	int TTmp;
	int FLAGG = 0;

	if (BLen > ALen) {
		Temp = A;
		A = B;
		B = Temp;
		TTmp = ALen;
		ALen = BLen;
		BLen = TTmp;
	}


	while (1) {
		if (Flag) {
			FLAGG = 1;
			Flag = 0;
		}

		if ((A[ALen - i] - '0') + (B[BLen - i] - '0') >= 10) {
			Flag = 1;
			A[ALen - i] = A[ALen - i] + (B[BLen - i] - '0') - 10;
		}
		else
			A[ALen - i] = A[ALen - i] + (B[BLen - i] - '0');

		if (FLAGG) {
			int j = 0;
			if ((A[ALen - i] - '0') + 1 == 10) {

				while (A[ALen - i - j] == '9') {
					A[ALen - i - j] -= 9;
					j++;
				}
				A[ALen - i - j] += 1;
			}

			else
				A[ALen - i] += 1;
			FLAGG = 0;
		}

		i++;
		if (ALen - i < 0 || BLen - i < 0) {
			if (ALen - i >= 0 && BLen - i < 0 && Flag) {
				while (ALen - i >= 0) {
					if ((A[ALen - i] - '0') + 1 == 10) {
						A[ALen - i] -= 9;
					}
					else
					{
						A[ALen - i] += 1;
						Flag = 0;
						break;
					}
					i++;
				}
			}
			break;
		}

	}
}