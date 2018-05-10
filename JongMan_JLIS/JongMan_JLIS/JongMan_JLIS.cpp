#include <iostream>

using namespace std;

/*
입력
입력의 첫 줄에는 테스트 케이스의 수 c ( 1 <= c <= 50 ) 가 주어집니다. 각 테스트 케이스의 첫 줄에는 A 와 B 의 길이 n 과 m 이 주어집니다 (1 <= n,m <= 100). 다음 줄에는 n 개의 정수로 A 의 원소들이, 그 다음 줄에는 m 개의 정수로 B 의 원소들이 주어집니다. 모든 원소들은 32비트 부호 있는 정수에 저장할 수 있습니다.

출력
각 테스트 케이스마다 한 줄에, JLIS 의 길이를 출력합니다.
*/

int N, M; // A 와 B 의 길이 n 과 m 이 주어집니다 (1 <= n,m <= 100)
int MAX;
int Cache[100][100];
int A[100] = { 0, }, B[100] = { 0, };

int Solve(int IsArr, int Count, int min);
int Max(int X, int Y) { if (X > Y) return X; else return Y; }

int main()
{
	int TC;
	int input;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> N >> M;
		MAX = 0;
		for (int j = 0; j < N; j++) 
			cin >> A[j];
		for (int j = 0; j < M; j++)
			cin >> B[j];
		for (int j = 0; j < 100; j++)
			for (int k = 0; k < 100; k++)
				Cache[j][k] = 0;


		cout << MAX << endl;
	}
	return 0;
}

int Solve(int AX, int BX)
{
	/* 하 안풀린다 난이도 하 인데 왜 못풀지.. 일단.. 풀이를 보았다..
	문자열 2개 합치는거니까 dvide 하는 개념으로.. 접근..해보자.. 일단.. 오늘은 접고 내일할거임
	*/

	

	//if (IsArr == 0) {
	//	for (int i = Count + 1; i < N; i++) {
	//		if (A[i] > A[Count]) { // 증가하고
	//			if (CacheA[i] == 0) // 계산 했던 곳이 아니면
	//				CacheA[Count] = Max(CacheA[Count], Solve(0, i, min) + 1);
	//			else // 계산 했던 곳이면
	//				CacheA[Count] = Max(CacheA[Count], CacheA[i] + 1);
	//		}
	//	}
	//	for (int i = min + 1; i < M; i++) {
	//		if (B[i] > A[Count]) { // 증가하고
	//			if (CacheB[i] == 0) // 계산 했던 곳이 아니면
	//				CacheA[Count] = Max(CacheA[Count], Solve(1, i, Count) + 1);
	//			else // 계산 했던 곳이면
	//				CacheA[Count] = Max(CacheA[Count], CacheB[i] + 1);
	//		}
	//	}

	//	if (CacheA[Count] == 0)
	//		CacheA[Count] = 1;
	//	MAX = Max(MAX, CacheA[Count]);
	//	return CacheA[Count];
	//}
}
