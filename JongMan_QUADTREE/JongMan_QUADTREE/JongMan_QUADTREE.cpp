#include <iostream>
#include <string>

using namespace std;

/*
입력
첫 줄에 테스트 케이스의 개수 C (C≤50)가 주어집니다. 그 후 C줄에 하나씩 쿼드 트리로 압축한 그림이 주어집니다. 모든 문자열의 길이는 1,000 이하이며, 원본 그림의 크기는 220 × 220 을 넘지 않습니다.

출력
각 테스트 케이스당 한 줄에 주어진 그림을 상하로 뒤집은 결과를 쿼드 트리 압축해서 출력합니다.
*/

string Solve(string& str, int& Cur);

int main()
{
	int TC;

	cin >> TC;

	for (int i = 0; i < TC; i++) {
		string Input;
		int Cur = -1;
		cin >> Input;
		cout << Solve(Input, Cur) << endl;
	}

	return 0;
}

string Solve(string& str, int& Cur)
{
	Cur++;
	// b나 w면 리턴.
	if (str[Cur] == 'b' || str[Cur] == 'w')
		return string(1, str[Cur]);
	/*
	x인 경우
	1 2 > 3 4
	3 4 > 1 2
	*/

	string First = Solve(str, Cur); // 첫번째 칸꺼 완성해서 저장
	string Second = Solve(str, Cur);// 두번째 칸꺼 완성해서 저장
	string Third = Solve(str, Cur);// 세번째 칸꺼 완성해서 저장
	string Fourth = Solve(str, Cur);// 네번째 칸꺼 완성해서 저장

	return "x" + Third + Fourth + First + Second; // 순서 바꿔주기.
}