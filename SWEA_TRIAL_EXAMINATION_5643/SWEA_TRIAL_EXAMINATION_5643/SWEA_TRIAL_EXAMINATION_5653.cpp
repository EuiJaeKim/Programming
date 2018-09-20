#include <iostream>
#include<vector>

using namespace std;

#define MAXLENGTH 700

int N; // 줄기 세포가 분포된 영역의 넓이 세로 크기 1≤N≤50
int M; // 줄기 세포가 분포된 영역의 넓이 가로 크기 1≤M≤50
int K; // 배양 시간 1≤K≤300

struct Cell {
	char LifeTime; // 생명력 0 = 빈칸  1~ 존재 or 사망
	char Time; // 활성상태까지 남은 시간 or 비활성까지 남은 시간
	char Active; // 활성 상태 0 = 사망, 1 = 비활성, 2 = 활성
};

Cell** Map;
vector<short> q;
vector<short> p;

void Init();
int TimeFlow();

int main()
{
	int TC;

	Map = new Cell*[MAXLENGTH];
	for (int i = 0; i < MAXLENGTH; i++)
		Map[i] = new Cell[MAXLENGTH];

	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		Init();
		printf("#%d %d\n", i, TimeFlow());
	}
	free(Map);
	return 0;
}

void Init()
{
	cin >> N >> M >> K;
	/* 초기화 */
	for (int i = 0; i < MAXLENGTH; i++)
		for (int j = 0; j < MAXLENGTH; j++) {
			Map[i][j].Active = 0;
			Map[i][j].LifeTime = 0;
			Map[i][j].Time = 0;
		}

	/* 입력 */
	int InputVal;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> InputVal;
			if (InputVal > 0) {
				Map[i + 324][j + 324].LifeTime = Map[i + 324][j + 324].Time = InputVal;
				Map[i + 324][j + 324].Active = 1;
				q.push_back(i + 324);
				q.push_back(j + 324);
			}
		}
}

int TimeFlow()
{
	short X, Y;

	for (int i = 0; i < K; i++)
	{
		if (i % 2 == 0) { // q
			while (!q.empty()) {
				X = q.at(0);
				Y = q.at(1);
				q.erase(q.begin());
				q.erase(q.begin());
				if (Map[X][Y].LifeTime != 0 && Map[X][Y].Active != 0) {// 셀이 존재하며 죽지않은 상태.

					Map[X][Y].Time--;

					if (Map[X][Y].Active == 1 && Map[X][Y].Time == 0) { // 비활성.
						Map[X][Y].Time = Map[X][Y].LifeTime;
						Map[X][Y].Active = 2;
					}
					else if (Map[X][Y].Active == 2 && Map[X][Y].Time + 1 == Map[X][Y].LifeTime) { // 활성.
						if (Map[X][Y + 1].LifeTime == 0) { // 동쪽 빈칸
							Map[X][Y + 1].Active = 1;
							Map[X][Y + 1].LifeTime = Map[X][Y + 1].Time = Map[X][Y].LifeTime;
							p.push_back(X);
							p.push_back(Y + 1);
						}
						else if (Map[X][Y + 1].Active == 1 && Map[X][Y + 1].LifeTime == Map[X][Y + 1].Time && Map[X][Y].LifeTime > Map[X][Y + 1].LifeTime) { // 빈칸이 아닌데 우선순위가 높을때.
							bool Flag = true;
							for (int j = 0; j < q.size(); j += 2) {
								if (q.at(j) == X && q.at(j + 1) == Y + 1) {
									Flag = false;
									break;
								}
							}
							if (Flag)
								Map[X][Y + 1].LifeTime = Map[X][Y + 1].Time = Map[X][Y].LifeTime;
						}

						if (Map[X][Y - 1].LifeTime == 0) { // 서쪽 빈칸
							Map[X][Y - 1].Active = 1;
							Map[X][Y - 1].LifeTime = Map[X][Y - 1].Time = Map[X][Y].LifeTime;
							p.push_back(X);
							p.push_back(Y - 1);
						}
						else if (Map[X][Y - 1].Active == 1 && Map[X][Y - 1].LifeTime == Map[X][Y - 1].Time && Map[X][Y].LifeTime > Map[X][Y - 1].LifeTime) { // 빈칸이 아닌데 우선순위가 높을때.
							bool Flag = true;
							for (int j = 0; j < q.size(); j += 2) {
								if (q.at(j) == X && q.at(j + 1) == Y - 1) {
									Flag = false;
									break;
								}
							}
							if (Flag)
								Map[X][Y - 1].LifeTime = Map[X][Y - 1].Time = Map[X][Y].LifeTime;
						}

						if (Map[X + 1][Y].LifeTime == 0) { // 남쪽 빈칸
							Map[X + 1][Y].Active = 1;
							Map[X + 1][Y].LifeTime = Map[X + 1][Y].Time = Map[X][Y].LifeTime;
							p.push_back(X + 1);
							p.push_back(Y);
						}
						else if (Map[X + 1][Y].Active == 1 && Map[X + 1][Y].LifeTime == Map[X + 1][Y].Time && Map[X][Y].LifeTime > Map[X + 1][Y].LifeTime) { // 빈칸이 아닌데 우선순위가 높을때.
							bool Flag = true;
							for (int j = 0; j < q.size(); j += 2) {
								if (q.at(j) == X + 1 && q.at(j + 1) == Y) {
									Flag = false;
									break;
								}
							}
							if (Flag)
								Map[X + 1][Y].LifeTime = Map[X + 1][Y].Time = Map[X][Y].LifeTime;
						}

						if (Map[X - 1][Y].LifeTime == 0) { // 북쪽 빈칸
							Map[X - 1][Y].Active = 1;
							Map[X - 1][Y].LifeTime = Map[X - 1][Y].Time = Map[X][Y].LifeTime;
							p.push_back(X - 1);
							p.push_back(Y);
						}
						else if (Map[X - 1][Y].Active == 1 && Map[X - 1][Y].LifeTime == Map[X - 1][Y].Time && Map[X][Y].LifeTime > Map[X - 1][Y].LifeTime) { // 빈칸이 아닌데 우선순위가 높을때.
							bool Flag = true;
							for (int j = 0; j < q.size(); j += 2) {
								if (q.at(j) == X - 1 && q.at(j + 1) == Y) {
									Flag = false;
									break;
								}
							}
							if (Flag)
								Map[X - 1][Y].LifeTime = Map[X - 1][Y].Time = Map[X][Y].LifeTime;
						}
					}

					if (Map[X][Y].Time == 0)
						Map[X][Y].Active = 0;
					else {
						p.push_back(X);
						p.push_back(Y);
					}
				}
			}
		}
		else { // p
			while (!p.empty()) {
				X = p.at(0);
				Y = p.at(1);
				p.erase(p.begin());
				p.erase(p.begin());
				if (Map[X][Y].LifeTime != 0 && Map[X][Y].Active != 0) {// 셀이 존재하며 죽지않은 상태.

					Map[X][Y].Time--;

					if (Map[X][Y].Active == 1 && Map[X][Y].Time == 0) { // 비활성.
						Map[X][Y].Time = Map[X][Y].LifeTime;
						Map[X][Y].Active = 2;
					}
					else if (Map[X][Y].Active == 2 && Map[X][Y].Time + 1 == Map[X][Y].LifeTime) { // 활성.
						if (Map[X][Y + 1].LifeTime == 0) { // 동쪽 빈칸
							Map[X][Y + 1].Active = 1;
							Map[X][Y + 1].LifeTime = Map[X][Y + 1].Time = Map[X][Y].LifeTime;
							q.push_back(X);
							q.push_back(Y + 1);
						}
						else if (Map[X][Y + 1].Active == 1 && Map[X][Y + 1].LifeTime == Map[X][Y + 1].Time && Map[X][Y].LifeTime > Map[X][Y + 1].LifeTime) { // 빈칸이 아닌데 우선순위가 높을때.
							bool Flag = true;
							for (int j = 0; j < p.size(); j += 2) {
								if (p.at(j) == X && p.at(j + 1) == Y + 1) {
									Flag = false;
									break;
								}
							}
							if (Flag)
								Map[X][Y + 1].LifeTime = Map[X][Y + 1].Time = Map[X][Y].LifeTime;
						}

						if (Map[X][Y - 1].LifeTime == 0) { // 서쪽 빈칸
							Map[X][Y - 1].Active = 1;
							Map[X][Y - 1].LifeTime = Map[X][Y - 1].Time = Map[X][Y].LifeTime;
							q.push_back(X);
							q.push_back(Y - 1);
						}
						else if (Map[X][Y - 1].Active == 1 && Map[X][Y - 1].LifeTime == Map[X][Y - 1].Time && Map[X][Y].LifeTime > Map[X][Y - 1].LifeTime) { // 빈칸이 아닌데 우선순위가 높을때.
							bool Flag = true;
							for (int j = 0; j < p.size(); j += 2) {
								if (p.at(j) == X && p.at(j + 1) == Y - 1) {
									Flag = false;
									break;
								}
							}
							if (Flag)
								Map[X][Y - 1].LifeTime = Map[X][Y - 1].Time = Map[X][Y].LifeTime;
						}

						if (Map[X + 1][Y].LifeTime == 0) { // 남쪽 빈칸
							Map[X + 1][Y].Active = 1;
							Map[X + 1][Y].LifeTime = Map[X + 1][Y].Time = Map[X][Y].LifeTime;
							q.push_back(X + 1);
							q.push_back(Y);
						}
						else if (Map[X + 1][Y].Active == 1 && Map[X + 1][Y].LifeTime == Map[X + 1][Y].Time && Map[X][Y].LifeTime > Map[X + 1][Y].LifeTime) { // 빈칸이 아닌데 우선순위가 높을때.
							bool Flag = true;
							for (int j = 0; j < p.size(); j += 2) {
								if (p.at(j) == X + 1 && p.at(j + 1) == Y) {
									Flag = false;
									break;
								}
							}
							if (Flag)
								Map[X + 1][Y].LifeTime = Map[X + 1][Y].Time = Map[X][Y].LifeTime;
						}

						if (Map[X - 1][Y].LifeTime == 0) { // 북쪽 빈칸
							Map[X - 1][Y].Active = 1;
							Map[X - 1][Y].LifeTime = Map[X - 1][Y].Time = Map[X][Y].LifeTime;
							q.push_back(X - 1);
							q.push_back(Y);
						}
						else if (Map[X - 1][Y].Active == 1 && Map[X - 1][Y].LifeTime == Map[X - 1][Y].Time && Map[X][Y].LifeTime > Map[X - 1][Y].LifeTime) { // 빈칸이 아닌데 우선순위가 높을때.
							bool Flag = true;
							for (int j = 0; j < p.size(); j += 2) {
								if (p.at(j) == X - 1 && p.at(j + 1) == Y) {
									Flag = false;
									break;
								}
							}
							if (Flag)
								Map[X - 1][Y].LifeTime = Map[X - 1][Y].Time = Map[X][Y].LifeTime;
						}
					}

					if (Map[X][Y].Time == 0)
						Map[X][Y].Active = 0;
					else {
						q.push_back(X);
						q.push_back(Y);
					}
				}
			}
		}
	}
	q.clear();
	p.clear();

	int Result = 0;
	for (int i = 0; i < MAXLENGTH; i++)
		for (int j = 0; j < MAXLENGTH; j++) {
			if (Map[i][j].Active != 0)
				Result++;
		}
	return Result;
}