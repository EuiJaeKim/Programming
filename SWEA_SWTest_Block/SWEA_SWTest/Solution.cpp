#include <iostream>
using namespace std;

#define Leng 30000

typedef struct LeafNode
{
	int Module;
	LeafNode* NextLeafNode;
}LeafNode;

typedef struct Node
{
	Node* NextNode[3];
	LeafNode* lfNode;
}Node;

Node* Root;
short MinArr[Leng];
short MaxArr[Leng];
bool PairArr[Leng] = { 0, };

void Init()
{
	Root = new Node;
	for (register int i = 0; i < 3; i++)
		Root->NextNode[i] = nullptr;
	Root->lfNode = nullptr;
}

void NewNode(Node* Front, int Count)
{
	Node* Temp;
	Temp = new Node();
	for (register int i = 0; i < 3; i++)
		Temp->NextNode[i] = nullptr;
	Temp->lfNode = nullptr;
	Front->NextNode[Count] = Temp;
}

void NewLeafNodeFromNode(Node* Front, int InputModule)
{
	LeafNode* Temp;
	Temp = new LeafNode();
	Temp->Module = InputModule;
	Temp->NextLeafNode = nullptr;
	Front->lfNode = Temp;
}

void NewLeafNodeFromLeafNode(LeafNode* Front, int InputModule) {
	LeafNode* Temp;
	Temp = new LeafNode();
	Temp->Module = InputModule;
	Temp->NextLeafNode = nullptr;
	Front->NextLeafNode = Temp;
}

void TreeDelete(Node* Current, int Count)
{
	LeafNode* Cur;
	if (Count == 15) {
		while (Current->lfNode) {
			Cur = Current->lfNode;
			delete(Cur);
			Current->lfNode = Current->lfNode->NextLeafNode;
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			if (Current->NextNode[i]) {
				TreeDelete(Current->NextNode[i], Count + 1);
			}
		}
		delete(Current->NextNode);
	}
}

int makeBlock(int module[][4][4])
{
	int Max, Min, Ret = 0;
	bool Flag;
	Node* CurrentNode;
	LeafNode* CurrentLeafNode;

	Init();
	/* 1. 트리 만들기 */
	for (register int i = 0; i < Leng; i++) {
		Max = 0;
		Min = 1000;
		CurrentNode = Root;
		for (register int x = 0; x < 4; x++) {
			for (register int y = 0; y < 4; y++) {
				if (Max < module[i][x][y])
					Max = module[i][x][y];
				if (Min > module[i][x][y])
					Min = module[i][x][y];
			}
		}
		if (Max != Min) {
			MinArr[i] = short(Min);
			MaxArr[i] = short(Max);
			for (register int x = 0; x < 4; x++) {
				for (register int y = 0; y < 4; y++) {
					if (CurrentNode->NextNode[module[i][x][y] - Min] == nullptr)
						NewNode(CurrentNode, module[i][x][y] - Min); // 달아주고
					CurrentNode = CurrentNode->NextNode[module[i][x][y] - Min];
				}
			}
			if (CurrentNode->lfNode == nullptr) { // 리프노드에 아무것도 없으면 달아준다.
				NewLeafNodeFromNode(CurrentNode, i);
			}
			else { // 리프노드에 무언가 있다면
				LeafNode* Front = nullptr;
				CurrentLeafNode = CurrentNode->lfNode;
				while (CurrentLeafNode->NextLeafNode != nullptr) {// 맨뒤 or 넣어야할 곳으로 이동한다.
					if (MaxArr[CurrentLeafNode->Module] > Max) {
						Front = CurrentLeafNode;
						CurrentLeafNode = CurrentLeafNode->NextLeafNode;
					}
					else
						break;
				}
				if (Front == nullptr) {// 바로 앞에꺼
					Front = CurrentNode->lfNode;
					NewLeafNodeFromNode(CurrentNode, i);
					CurrentNode->lfNode->NextLeafNode = Front;
				}
				else if (CurrentLeafNode->NextLeafNode != nullptr) {// 중간쯤 어딘가
					NewLeafNodeFromLeafNode(Front, i);
					Front->NextLeafNode->NextLeafNode = CurrentLeafNode;
				}
				else { // 마지막
					NewLeafNodeFromLeafNode(CurrentLeafNode, i);
				}
			}
		}
	}

	//printf("만들기 끝\n");
	/* 2. Pair 검색 과 LeafNode 삭제 */
	int CCount;
	for (register int i = 0; i < Leng; i++) {
		if (!PairArr[i]) {
			CCount = 0;
			LeafNode* LeafNodeCmp[4] = { nullptr,nullptr ,nullptr ,nullptr };
			CurrentNode = Root;
			Flag = false;
			for (register int x = 0; x < 4; x++) {
				for (register int y = 3; y >= 0; y--) {
					if (CurrentNode->NextNode[(MaxArr[i] - module[i][x][y])] != nullptr)
						CurrentNode = CurrentNode->NextNode[(MaxArr[i] - module[i][x][y])];
					else {
						Flag = true;
						break;
					}
				}
				if (Flag)
					break;
			}
			/* Pair를 찾음. */
			if (!Flag) {
				CurrentLeafNode = CurrentNode->lfNode;
				while (CurrentNode->lfNode != nullptr) {
					if (PairArr[CurrentLeafNode->Module]) {
						CurrentNode->lfNode = CurrentLeafNode->NextLeafNode;
					}
					else {
						LeafNodeCmp[0] = CurrentNode;
						CCount++;
						break;
					}
				}
			}
			/* 쳌 */
			CurrentNode = Root;
			Flag = false;
			for (register int y = 0; y < 4; y++) {
				for (register int x = 0; x < 4; x++) {
					if (CurrentNode->NextNode[(MaxArr[i] - module[i][x][y])] != nullptr)
						CurrentNode = CurrentNode->NextNode[(MaxArr[i] - module[i][x][y])];
					else {
						Flag = true;
						break;
					}
				}
				if (Flag)
					break;
			}
			/* Pair를 찾음. */
			while (!Flag && CurrentNode->lfNode != nullptr) {
				CurrentLeafNode = CurrentNode->lfNode;
				if (PairArr[CurrentLeafNode->Module]) {
					CurrentNode->lfNode = CurrentLeafNode->NextLeafNode;
					delete(CurrentLeafNode);
				}
				else {
					LeafNodeCmp[1] = CurrentNode;
					CCount++;
					break;
				}
			}
			CurrentNode = Root;
			Flag = false;
			for (register int x = 3; x >= 0; x--) {
				for (register int y = 0; y < 4; y++) {
					if (CurrentNode->NextNode[(MaxArr[i] - module[i][x][y])] != nullptr)
						CurrentNode = CurrentNode->NextNode[(MaxArr[i] - module[i][x][y])];
					else {
						Flag = true;
						break;
					}
				}
				if (Flag)
					break;
			}
			/* Pair를 찾음. */
			while (!Flag && CurrentNode->lfNode != nullptr) {
				CurrentLeafNode = CurrentNode->lfNode;
				if (PairArr[CurrentLeafNode->Module]) {
					CurrentNode->lfNode = CurrentLeafNode->NextLeafNode;
					delete(CurrentLeafNode);
				}
				else {
					LeafNodeCmp[2] = CurrentNode;
					CCount++;
					break;

				}
			}
			CurrentNode = Root;
			Flag = false;
			for (register int y = 3; y >= 0; y--) {
				for (register int x = 3; x >= 0; x--) {
					if (CurrentNode->NextNode[(MaxArr[i] - module[i][x][y])] != nullptr)
						CurrentNode = CurrentNode->NextNode[(MaxArr[i] - module[i][x][y])];
					else {
						Flag = true;
						break;
					}
				}
				if (Flag)
					break;
			}
			/* Pair를 찾음. */
			while (!Flag && CurrentNode->lfNode != nullptr) {
				CurrentLeafNode = CurrentNode->lfNode;
				if (PairArr[CurrentLeafNode->Module]) {
					CurrentNode->lfNode = CurrentLeafNode->NextLeafNode;
					delete(CurrentLeafNode);
				}
				else {
					LeafNodeCmp[3] = CurrentNode;
					CCount++;
					break;
				}
			}
			/* 쳌 */
			/* Pair 가장 큰 값을 찾아서 Pair 체크. */
			if (CCount > 0) {
				int CmpMax = 0;
				int CmpMaxi;
				for (int j = 0; j < 4; j++) {
					if (LeafNodeCmp[j]) {
						if (MaxArr[LeafNodeCmp[j]->lfNode->Module] > CmpMax) {
							CmpMax = MaxArr[LeafNodeCmp[j]->lfNode->Module];
							CmpMaxi = j;
						}
					}
				}

				Ret += (CmpMax + MinArr[i])-(MaxArr[i] - MinArr[i]);
				PairArr[LeafNodeCmp[CmpMaxi]->lfNode->Module] = true;
				PairArr[i] = true;
				CurrentLeafNode = LeafNodeCmp[CmpMaxi]->lfNode;
				LeafNodeCmp[CmpMaxi]->lfNode = CurrentLeafNode->NextLeafNode;
				delete(CurrentLeafNode);
			}
		}
	}
	//printf("Test\n");

	/* 트리 리셋 */
	TreeDelete(Root, 0);

	return Ret;
}