#include <cstdio>
#include <cstdlib>

int N;
int Human[10][4];
int HumCount, DoorCount;
int Door[2][3];
int DoorQueue[2][10];
int TempQueue[2][10];
int QueueCountA, QueueCountB;
int Min;

void Solve(int Cur);
void InitDoorQueue();
void CopyQueue();
void SelSort();
int Cal();

int main()
{
	int TC, Temp;

	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		scanf("%d", &N);
		HumCount = 0;

		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 4; k++)
				Human[j][k] = -1;

		DoorCount = 0;
		Min = 5000;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				scanf("%d", &Temp);
				if (Temp == 1) {
					Human[HumCount][0] = j;
					Human[HumCount++][1] = k;
				}
				else if (Temp > 1) {
					Door[DoorCount][0] = Temp;
					Door[DoorCount][1] = j;
					Door[DoorCount++][2] = k;
				}
			}
		}

		for (int j = 0; j < HumCount; j++) {
			Human[j][2] = abs(Human[j][0] - Door[0][1]) + abs(Human[j][1] - Door[0][2]);
			Human[j][3] = abs(Human[j][0] - Door[1][1]) + abs(Human[j][1] - Door[1][2]);
		}
		QueueCountA = 0;
		QueueCountB = 0;
		InitDoorQueue();
		Solve(0);
		printf("#%d %d\n", i, Min);
	}

	return 0;
}

void InitDoorQueue()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 10; j++)
			DoorQueue[i][j] = -1;
}

void CopyQueue()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 10; j++)
			TempQueue[i][j] = DoorQueue[i][j];
}

void Solve(int Cur)
{
	int Temp;


	if (Cur != HumCount - 1) {
		DoorQueue[0][QueueCountA++] = Cur;
		Solve(Cur + 1);
		QueueCountA--;
		DoorQueue[0][QueueCountA] = -1;
		DoorQueue[1][QueueCountB++] = Cur;
		Solve(Cur + 1);
		QueueCountB--;
		DoorQueue[1][QueueCountB] = -1;
	}
	else {
		DoorQueue[0][QueueCountA++] = Cur;
		CopyQueue();
		SelSort();
		Temp = Cal();
		Min = Min > Temp ? Temp : Min;
		QueueCountA--;
		DoorQueue[0][QueueCountA] = -1;

		DoorQueue[1][QueueCountB++] = Cur;
		CopyQueue();
		SelSort();
		Temp = Cal();
		Min = Min > Temp ? Temp : Min;
		QueueCountB--;
		DoorQueue[1][QueueCountB] = -1;
	}
}

void SelSort()
{
	int Temp;

	for (int i = 0; i < HumCount; i++) {
		for (int j = i + 1; j < HumCount; j++) {
			if (TempQueue[0][i] != -1 && TempQueue[0][j] != -1 && Human[TempQueue[0][i]][2] > Human[TempQueue[0][j]][2]) {
				Temp = TempQueue[0][j];
				TempQueue[0][j] = TempQueue[0][i];
				TempQueue[0][i] = Temp;
			}

			if (TempQueue[1][i] != -1 && TempQueue[1][j] != -1 && Human[TempQueue[1][i]][3] > Human[TempQueue[1][j]][3]) {
				Temp = TempQueue[1][j];
				TempQueue[1][j] = TempQueue[1][i];
				TempQueue[1][i] = Temp;
			}
		}
	}
}

int Cal()
{
	int Count = 0, ACount = 0, BCount = 0, TempA = 0, TempB = 0, FinalCount = 0;
	int DoorDown[2][3][2];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 2; k++)
				DoorDown[i][j][k] = -1;

	while (1) {
		if (ACount > 0 || BCount > 0) {
			for (int i = 0; i < 3; i++) {
				if (DoorDown[0][i][0] != -1 && DoorDown[0][i][1] == Door[0][0]) {
					DoorDown[0][i][0] = -1;
					ACount--;
					FinalCount++;
				}
				if (DoorDown[1][i][0] != -1 && DoorDown[1][i][1] == Door[1][0]) {
					DoorDown[1][i][0] = -1;
					BCount--;
					FinalCount++;
				}
			}

			if (FinalCount == HumCount)
				return Count;

			for (int i = 0; i < 3; i++) {
				if (DoorDown[0][i][0] != -1)
					DoorDown[0][i][1]++;
			}
			for (int i = 0; i < 3; i++) {
				if (DoorDown[1][i][0] != -1)
					DoorDown[1][i][1]++;
			}

		}

		if (ACount < 3 && TempA < QueueCountA) {
			for (int i = TempA; i < QueueCountA; i++) {
				if (Human[TempQueue[0][i]][2] <= Count && ACount < 3) {
					for (int j = 0; j < 3; j++) {
						if (DoorDown[0][j][0] == -1)
						{
							DoorDown[0][j][0] = TempQueue[0][i];
							if (Human[TempQueue[0][i]][2] < Count)
								DoorDown[0][j][1] = 1;
							else
								DoorDown[0][j][1] = 0;
							ACount++;
							TempA++;
							break;
						}
					}

				}
			}
		}
		if (BCount < 3 && TempB < QueueCountB) {
			for (int i = TempB; i < QueueCountB; i++) {
				if (Human[TempQueue[1][i]][3] <= Count && BCount < 3) {
					for (int j = 0; j < 3; j++) {
						if (DoorDown[1][j][0] == -1)
						{
							DoorDown[1][j][0] = TempQueue[1][i];
							if (Human[TempQueue[1][i]][3] < Count)
								DoorDown[1][j][1] = 1;
							else
								DoorDown[1][j][1] = 0;
							BCount++;
							TempB++;
							break;
						}
					}
				}
			}
		}
		Count++;
	}

}