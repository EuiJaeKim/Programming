#include <iostream>
#include <cstdio>
using namespace std;

int Map[6] = { 0, };
char HumName[10][10]; // 면접관 이름
int HumNameLen[10]; // 면접관 이름 길이
int HumPoint[10]; // 면접관 점수
int Num; // 면접관 수
int Max;
int Visit[10] = { 0, };

void init();
void dfs(int r, int s);
int Check(int CurNum);
void Back(int CurNum);

int main()
{
	int TC;

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cin >> Num;
		for (int j = 0; j < Num; j++) {
			cin >> HumNameLen[j];
			for (int k = 0; k < HumNameLen[j]; k++)
				cin >> HumName[j][k];
			cin >> HumPoint[j];
		}
		init();
		dfs(0, 0);
		if (Max != 10001)
			printf("#%d %d\n", i, Max);
		else
			printf("#%d -1\n", i);
	}

	return 0;
}

void init()
{
	for (int i = 0; i < 6; i++)
		Map[i] = 0;
	for (int i = 0; i < Num; i++)
		Visit[i] = 0;
	Max = 10001;
}

void dfs(int r, int s)
{
	if (r > Num)
	{
		if (s < Max && Check(-1) == 1)
			Max = s;
		return;
	}

	int result;

	for (int i = 0; i < Num; i++)
	{
		if (Visit[i] == 1)
			continue;

		Visit[i] = 1;

		result = s + HumPoint[i];

		if (Check(i) == 1)
		{
			if (result < Max)
				Max = result;
			Visit[i] = 0;
			Back(i);
			continue;
		}

		dfs(r + 1, result);

		Visit[i] = 0;
		Back(i);
	}

	return;
}

int Check(int CurNum)
{
	if (CurNum >= 0) {
		for (int i = 0; i < HumNameLen[CurNum]; i++) {
			if (HumName[CurNum][i] == 'S')
				Map[0]++;
			else if (HumName[CurNum][i] == 'A')
				Map[1]++;
			else if (HumName[CurNum][i] == 'M')
				Map[2]++;
			else if (HumName[CurNum][i] == 'U')
				Map[3]++;
			else if (HumName[CurNum][i] == 'N')
				Map[4]++;
			else if (HumName[CurNum][i] == 'G')
				Map[5]++;
		}
	}
	if (Map[0] >= 2 && Map[1] >= 1 && Map[2] >= 1 && Map[3] >= 1 && Map[4] >= 1 && Map[5] >= 1)
		return 1;
	else
		return -1;
}

void Back(int CurNum)
{
	for (int i = 0; i < HumNameLen[CurNum]; i++) {
		if (HumName[CurNum][i] == 'S')
			Map[0]--;
		else if (HumName[CurNum][i] == 'A')
			Map[1]--;
		else if (HumName[CurNum][i] == 'M')
			Map[2]--;
		else if (HumName[CurNum][i] == 'U')
			Map[3]--;
		else if (HumName[CurNum][i] == 'N')
			Map[4]--;
		else if (HumName[CurNum][i] == 'G')
			Map[5]--;
	}
}