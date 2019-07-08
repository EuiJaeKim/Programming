#include <iostream>

using namespace std;

typedef struct Node {
	char Name[60];
	short Count;
	Node* Next;
}Node;

Node Map[50];

char* _strcpy(char* dst, const char* src) {
	char* cp = dst;
	while (*cp++ = *src++)
		;
	return dst;
}

void Init()
{
	/* 초기 Map 셋팅 = 1967 - Start로 해싱. 동년 값은 chaining*/
	Node* Temp;
	_strcpy(Map[0].Name, "DavidBowie");
	Map[0].Count = 1;
	_strcpy(Map[2].Name, "SpaceOddity");
	Map[2].Count = 1;
	_strcpy(Map[3].Name, "TheManWhoSoldTheWorld");
	Map[3].Count = 1;
	_strcpy(Map[4].Name, "HunkyDory");
	Map[4].Count = 1;
	_strcpy(Map[5].Name, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
	Map[5].Count = 1;
	_strcpy(Map[6].Name, "AladdinSane");
	Map[6].Count = 2;
	Temp = new Node();
	_strcpy(Temp->Name, "PinUps");
	Map[6].Next = Temp;
	_strcpy(Map[7].Name, "DiamondDogs");
	Map[7].Count = 1;
	_strcpy(Map[8].Name, "YoungAmericans");
	Map[8].Count = 1;
	_strcpy(Map[9].Name, "StationToStation");
	Map[9].Count = 1;
	_strcpy(Map[10].Name, "Low");
	Map[10].Count = 2;
	Temp = new Node();
	_strcpy(Temp->Name, "Heroes");
	Map[10].Next = Temp;
	_strcpy(Map[12].Name, "Lodger");
	Map[12].Count = 1;
	_strcpy(Map[13].Name, "ScaryMonstersAndSuperCreeps");
	Map[13].Count = 1;
	_strcpy(Map[16].Name, "LetsDance");
	Map[16].Count = 1;
	_strcpy(Map[17].Name, "Tonight");
	Map[17].Count = 1;
	_strcpy(Map[20].Name, "NeverLetMeDown");
	Map[20].Count = 1;
	_strcpy(Map[26].Name, "BlackTieWhiteNoise");
	Map[26].Count = 1;
	_strcpy(Map[28].Name, "1.Outside");
	Map[28].Count = 1;
	_strcpy(Map[30].Name, "Earthling");
	Map[30].Count = 1;
	_strcpy(Map[32].Name, "Hours");
	Map[32].Count = 1;
	_strcpy(Map[35].Name, "Heathen");
	Map[35].Count = 1;
	_strcpy(Map[36].Name, "Reality");
	Map[36].Count = 1;
	_strcpy(Map[46].Name, "TheNextDay");
	Map[46].Count = 1;
	_strcpy(Map[49].Name, "BlackStar");
	Map[49].Count = 1;
}


void Search(int Start, int End)
{
	Node* Current;
	/* Start, End 값 언더,오버플로우 처리 */
	if (Start < 1967)
		Start = 1967;
	if (End > 2016)
		End = 2016;
	int Ret=0;
	/* 총 갯수 */
	for (int i = 0; Start + i <= End; i++) { 
		if (Map[Start - 1967 + i].Name[0] != 0) {
			Ret += Map[Start - 1967 + i].Count;
		}
	}
	cout << Ret << endl;
	/* 실 값들 출력 */
	for (int i = 0; Start + i <= End; i++) {
		Current = &Map[Start - 1967 + i];
		while (Current->Name[0] != 0) {
			printf("%d %s\n", Start+i, Current->Name);
			if (Current->Next != nullptr)
				Current = Current->Next;
			else
				break;
		}
	}

}

int main()
{
	Init();
	int Input, Start, End;
	cin >> Input;
	for (int i = 0; i < Input; i++) {
		cin >> Start >> End;
		Search(Start, End);
	}
	return 0;
}