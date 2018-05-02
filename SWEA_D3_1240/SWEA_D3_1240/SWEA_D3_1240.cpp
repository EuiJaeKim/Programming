#include <cstdio>
#include <cstring>
char Input[101];
char Zero[] = "0001101";
char One[] = "0011001";
char Two[] = "0010011";
char Three[] = "0111101";
char Four[] = "0100011";
char Five[] = "0110001";
char Six[] = "0101111";
char Seven[] = "0111011";
char Eight[] = "0110111";
char Nine[] = "0001011";
int Result;
int N, M;
void Solve(int X);

int main()
{
	int T;
	int Temp;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d %d", &N, &M);
		Temp = -1;
		for (int j = 0; j < N; j++) {
			scanf("%s", &Input);

			if (Temp == -1) {
				for (int k = 0; k < N; k++) {
					if (Input[k] == '1') {
						Temp = k;
						Solve(k);
						break;
					}
				}
			}
		}
		printf("#%d %d\n", i, Result);

	}


	return 0;
}

void Solve(int X)
{
	int Flag = 0;
	int Code[8] = { -1, };
	char Tmp[8];
	Tmp[7] = '\0';
	for (int i = 0; i < 8; i++) {
		if (Code[0] == -1) {// 첫번째 숫자가 정해지지 않았을때
			while (X >= 0) {
				for (int j = 0; j < 7; j++) {
					Tmp[j] = Input[X + j];
				}

				if (strcmp(Tmp, Zero) == 0) {
					Code[i] = 0;
					break;
				}
				else if (strcmp(Tmp, One) == 0) {
					Code[i] = 1;
					break;
				}
				else if (strcmp(Tmp, Two) == 0) {
					Code[i] = 2;
					break;
				}
				else if (strcmp(Tmp, Three) == 0) {
					Code[i] = 3;
					break;
				}
				else if (strcmp(Tmp, Four) == 0) {
					Code[i] = 4;
					break;
				}
				else if (strcmp(Tmp, Five) == 0) {
					Code[i] = 5;
					break;
				}
				else if (strcmp(Tmp, Six) == 0) {
					Code[i] = 6;
					break;
				}
				else if (strcmp(Tmp, Seven) == 0) {
					Code[i] = 7;
					break;
				}
				else if (strcmp(Tmp, Eight) == 0) {
					Code[i] = 8;
					break;
				}
				else if (strcmp(Tmp, Nine) == 0) {
					Code[i] = 9;
					break;
				}
				if (Code[i] == -1)
					X--;
			}
		}
		else { // 첫번째가 정해졌다.
			X += 7;
			for (int j = 0; j < 7; j++) {
				Tmp[j] = Input[X + j];
			}
			if (strcmp(Tmp, Zero) == 0)
				Code[i] = 0;
			else if (strcmp(Tmp, One) == 0)
				Code[i] = 1;
			else if (strcmp(Tmp, Two) == 0)
				Code[i] = 2;
			else if (strcmp(Tmp, Three) == 0)
				Code[i] = 3;
			else if (strcmp(Tmp, Four) == 0)
				Code[i] = 4;
			else if (strcmp(Tmp, Five) == 0)
				Code[i] = 5;
			else if (strcmp(Tmp, Six) == 0)
				Code[i] = 6;
			else if (strcmp(Tmp, Seven) == 0)
				Code[i] = 7;
			else if (strcmp(Tmp, Eight) == 0)
				Code[i] = 8;
			else if (strcmp(Tmp, Nine) == 0)
				Code[i] = 9;
		}
	}


	if (((Code[0] + Code[2] + Code[4] + Code[6]) * 3 + Code[1] + Code[3] + Code[5] + Code[7]) % 10 == 0)
		Result = (Code[0] + Code[1] + Code[2] + Code[3] + Code[4] + Code[5] + Code[6] + Code[7]);
	else
		Result = 0;
}