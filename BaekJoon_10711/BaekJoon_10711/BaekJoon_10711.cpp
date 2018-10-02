#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int X;
	int Y;
};

int H;
int W;
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
char** Map;
int** CountMap;
vector<Node> PossibleNodeList;

void Init();
int Solve();

int main()
{
	Init();

	cout << Solve() << endl;

	return 0;
}

void Init()
{
	cin >> H >> W;

	Map = new char*[H];
	CountMap = new int*[H];
	for (int i = 0; i < H; i++) {
		Map[i] = new char[W];
		CountMap[i] = new int[W];
	}
		

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> Map[i][j];
			CountMap[i][j] = 0;
		}
	}
		
	int Count;
	Node Nde;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (Map[i][j] != '.' && Map[i][j] < '9') {
				Count = 0;
				for (int k = 0; k < 8; k++)
					if (Map[i + dx[k]][j + dy[k]] == '.')
						Count++;
				CountMap[i][j] = Count;

				if (Count >= Map[i][j] - '0') {
					Nde.X = i;
					Nde.Y = j;
					Map[i][j] = 'A';
					PossibleNodeList.push_back(Nde);
				}
			}
			else {
				CountMap[i][j] = -1;
			}
		}
	}
}

int Solve()
{
	int Time = 0;
	int Count;
	Node Nde;

	while (1) {
		Count = PossibleNodeList.size();
		for (int i = 0; i < Count; i++) {

			Map[PossibleNodeList[i].X][PossibleNodeList[i].Y] = '.';
			CountMap[PossibleNodeList[i].X][PossibleNodeList[i].Y] = -1;
			for (int j = 0; j < 8; j++) {
				if (CountMap[PossibleNodeList[i].X + dx[j]][PossibleNodeList[i].Y + dy[j]] != -1 && Map[PossibleNodeList[i].X + dx[j]][PossibleNodeList[i].Y + dy[j]] != 'A') {
					CountMap[PossibleNodeList[i].X + dx[j]][PossibleNodeList[i].Y + dy[j]]++;
					if (CountMap[PossibleNodeList[i].X + dx[j]][PossibleNodeList[i].Y + dy[j]] == Map[PossibleNodeList[i].X + dx[j]][PossibleNodeList[i].Y + dy[j]] - '0') {
						Nde.X = PossibleNodeList[i].X + dx[j];
						Nde.Y = PossibleNodeList[i].Y + dy[j];
						Map[PossibleNodeList[i].X + dx[j]][PossibleNodeList[i].Y + dy[j]] = 'A';
						PossibleNodeList.push_back(Nde);
					}
				}
			}
		}

		if (PossibleNodeList.size() == Count)
			break;
		else {
			Time++;
			PossibleNodeList.erase(PossibleNodeList.begin(), PossibleNodeList.begin()+ Count);
		}
	}
	return Time+1;
}