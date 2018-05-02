#include <cstdio>
int Map[100][2];
int Visit[100][2];

int Solve(int Start);
int main()
{
	int TC, LineCount;
	int Too, From;
	for (int i = 1; i <= 10; i++) {

		for (int j = 0; j < 100; j++)
			for (int k = 0; k < 2; k++) {
				Map[j][k] = -1;
				Visit[j][k] = 0;
			}


		scanf("%d %d", &TC, &LineCount);

		for (int j = 0; j < LineCount; j++) {
			scanf("%d", &From);
			scanf("%d", &Too);
			if (Map[From][0] == -1)
				Map[From][0] = Too;
			else
				Map[From][1] = Too;
		}
		printf("#%d %d\n", TC, Solve(0));
	}

}

int Solve(int Start)
{

	if (Start == 99)
		return 1;
	if ((Map[Start][0] == -1) || (Visit[Start][0] == 1 && Visit[Start][1] == 1) || (Map[Start][0] != -1 && Visit[Start][0] == 1 && Map[Start][1] == -1)) // 갈길이 없는 경우
		return 0;
	else {// 길이 어딘가는 갈수 있는듯
		int Temp;

		for (int i = 0; i < 2; i++) {
			Visit[Start][i] = 1;
			Temp = Solve(Map[Start][i]);
			if (Temp == 1)
				return 1;
		}
	}
	return 0;
}