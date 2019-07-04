
#define AlpaMax 26

typedef struct MyStruct
{
	MyStruct* Next[AlpaMax];
	int Count;
}MyStruct;

MyStruct* Root;

void NewNode(MyStruct* Front, int Count)
{
	MyStruct* Temp;
	Temp = new MyStruct();
	Temp->Count = 0;
	Front->Next[Count] = Temp;
}

void init(void) {

	if (Root != nullptr) {
		delete (Root);
	}

	MyStruct* Temp;
	Temp = new MyStruct();
	Temp->Count = 0;

	Root = Temp;
}

void insert(int buffer_size, char* buf) {
	MyStruct* CurNode;
	CurNode = Root;

	for (int i = 0; i < buffer_size; i++) {
		CurNode->Count++;
		if (CurNode->Next[buf[i] - 'a'] == nullptr)
			NewNode(CurNode, buf[i] - 'a');
		CurNode = CurNode->Next[buf[i] - 'a'];
	}
	CurNode->Count++;
}

int query(int buffer_size, char* buf) {
	MyStruct* CurNode;
	CurNode = Root;
	for (int i = 0; i < buffer_size; i++) {
		if (CurNode->Next[buf[i] - 'a'] == nullptr)
			return 0;
		CurNode = CurNode->Next[buf[i] - 'a'];
	}
	return CurNode->Count;
}