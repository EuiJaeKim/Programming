#include <cstdio>

int Client[1000][3] = { 0 }; // 0 도착 시간 1 접수창구 번호 2 정비 창구 번호
int N[9][2] = { 0 };
int M[9][2] = { 0 };
int ClientCount;
int NC;// 접수 창구
int MC;// 정비 창구
int GoalN, GoalM;
int Solve();

int main()
{
	int TC;

	scanf("%d", &TC);

	for (int i = 1; i <= TC; i++) {

		scanf("%d %d %d %d %d", &NC, &MC, &ClientCount, &GoalN, &GoalM);

		for (int j = 0; j < NC; j++) {
			scanf("%d", &N[j][0]);
			N[j][1] = -1;
		}
		for (int j = 0; j < MC; j++) {
			scanf("%d", &M[j][0]);
			M[j][1] = -1;
		}
		for (int j = 0; j < ClientCount; j++)
			scanf("%d", &Client[j][0]);

		printf("#%d %d\n", i, Solve());
		for (int j = 0; j < ClientCount; j++) {
			Client[j][0] = 0;
			Client[j][1] = 0;
			Client[j][2] = 0;
		}
	}

	return 0;
}

int Solve()
{
	int LastClient = 0; // 초기값 0
	int CurNC = 0, CurMC = 0, WaitC = 0, IngC = 0, IngCN = 0, WaitCN = 0, k = 0, Result = 0;

	int Waiting[1000];
	int WaitingN[1000];
	for (int i = 0; i < 1000; i++) {
		Waiting[i] = -1;
		WaitingN[i] = -1;
	}


	while (LastClient != ClientCount) {

		/* 접수 */
		for (int i = 0; i < NC; i++) {
			if (N[i][1] != -1 && Client[N[i][1]][1] == N[i][0]) { //손님이 계신데 상담시간이 다끝났어
				Client[N[i][1]][1] = i + 1; // 접수 창구 어디에서 하셨는지 저장해
				Waiting[WaitC++] = N[i][1]; //대기줄에다가 넣어
				N[i][1] = -1; // 자리 비우고 
			}
		}
		if (Client[ClientCount - 1][0] >= k) {
			for (int i = 0; i < ClientCount; i++) {
				if (Client[i][0] == k)
					WaitingN[WaitCN++] = i; // 손님 오셨다 받아라
			}
			k++;
		}

		if (CurNC < ClientCount && IngCN < WaitCN) {// 접수 창구에 들어간 손님이 전체 손님 수보다 작을때 도라
			for (int i = 0; i < NC; i++) {
				if (N[i][1] == -1 && IngCN < WaitCN) { // 창구가 비여있고 고객이 남아써
					N[i][1] = WaitingN[IngCN++];
					CurNC++;
				}
			}
		}

		for (int i = 0; i < NC; i++) {
			if (N[i][1] != -1 && Client[N[i][1]][1] < N[i][0]) {// 창구에 손님이 계시고 그손님은 상담중
				Client[N[i][1]][1]++; // 손님 상담 시간+1
			}
		}
		/* 접수 */
		/* 정비 */
		for (int i = 0; i < MC; i++) {
			if (M[i][1] != -1 && Client[M[i][1]][2] == M[i][0]) { //손님이 계신데 상담시간이 다끝났어
				Client[M[i][1]][2] = i + 1; // 정비 창구 어디에서 하셨는지 저장해
				M[i][1] = -1; // 자리 비우고 
				LastClient++;
			}
		}
		if (IngC < WaitC) // 손님 기다린다 손님받아라
			for (int i = 0; i < MC; i++) {
				if (M[i][1] == -1 && IngC < WaitC) {// 창구가 비여있고 고객이 대기중이야
					M[i][1] = Waiting[IngC++];// 대기중인 손님 셋팅
					CurMC++;
				}
			}
		for (int i = 0; i < MC; i++) {
			if (M[i][1] != -1 && Client[M[i][1]][2] < M[i][0]) // 창구에 손님이 계시고 그손님은 상담중
				Client[M[i][1]][2]++; // 손님 정비 시간+1
		}
		/* 정비 */
	}

	for (int i = 0; i < ClientCount; i++) {
		if (Client[i][1] == GoalN && Client[i][2] == GoalM)
			Result += i + 1;
	}

	if (Result == 0)
		return -1;
	else
		return Result;
}