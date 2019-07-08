#include <iostream>
#include <cstring>
#include <algorithm>
#define AlpaMax 26
using namespace std;

int N, M;

typedef struct Node {
	Node* Next[AlpaMax];
	char Name[20];
	short Count;
} Node;


Node* Root;
char Result[500000][20];
int ResultCount;


void NewNode(Node* Front, int Cnt)
{
	Node* Temp;
	Temp = new Node();
	Temp->Count = 0;
	Front->Next[Cnt] = Temp;
}

void Init()
{
	cin >> N >> M;
	char Input[20];
	Node* Current;
	int j;

	Root = new Node();
	Root->Count = 0;

	for (int i = 0; i < N; i++) {
		Current = Root;
		cin >> Input;
		for (j = 0; Input[j] != 0; j++) {
			Current->Count++;
			if (Current->Next[Input[j] - 'a'] == nullptr) {
				NewNode(Current, Input[j] - 'a');
			}
			Current = Current->Next[Input[j] - 'a'];
		}
		for (j = 0; Input[j] != 0; j++) {
			Current->Name[j] = Input[j];
		}
		Current->Count++;
	}
}
//int _strcmp(char* arr1, char* arr2) {
//	int i = 0;
//	while (arr1[i] != 0 || arr2[i] != 0) {
//		if (arr1[i] > arr2[i])
//			return arr1[i] - arr2[i];       // arr1 > arr2 이면 양수
//		else if (arr1[i] < arr2[i])
//			return arr1[i] - arr2[i];       // arr1 < arr2 이면 음수
//		i++;
//	}
//	return 0;       // arr1 == arr1 이면 0
//}

int _strcmp(const char* s1, const char* s2) {
	int ret = 0;
	while (!(ret = *(unsigned char*)s1 - *(unsigned char*)s2) && *s2)
		++s1, ++s2;

	if (ret < 0) {
		ret = -1;
	}
	else if (ret > 0) {
		ret = 1;
	}

	return ret;
}

char* _strcpy(char* dst, const char* src) {
	char* cp = dst;
	while (*cp++ = *src++)
		;
	return dst;
}

int sort_function(const void* a, const void* b) {
	char* fir = (char*)a;
	char* sec = (char*)b;
	while (fir && sec) {
		if (fir > sec)
			return 1;
		else if (fir < sec)
			return -1;
		fir++;
		sec++;
	}
	if (fir == nullptr && sec == nullptr)
		return 0;
	if (fir)
		return 1;
	else
		return -1;
}

void Merge(int low, int mid, int high)
{
	int h = low, j = mid + 1;
	int i = low;

	// 하나씩 비교하며 작은 것 순서대로 b배열에 넣어줍니다.
	while (h <= mid && j <= high)
	{
		if (arr[h] < arr[j])
			b[i] = arr[h++];
		else
			b[i] = arr[j++];
		i++;
	}

	// 한쪽 배열 탐색이 다 끝나면, 나머지 배열을 끝까지 채워 넣어줍니다.
	if (h > mid)
	{
		for (int k = j; k <= high; k++)
			b[i++] = arr[k];
	}
	else
	{
		for (int k = h; k <= mid; k++)
			b[i++] = arr[k];
	}
	// 정렬된 결과를 arr[low:high]까지 넣어줍니다. 키를 포함하는 레코드의 크기가 큰 경우 많은 시간을 소요합니다.
	for (int k = low; k <= high; k++)
		arr[k] = b[k];
}

void MergeSort(int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		//divide
		MergeSort(low, mid);
		MergeSort(mid + 1, high);

		//conquer
		Merge(low, mid, high);
	}
}

void Search()
{
	char Input[20];
	bool Check;
	Node* Current;
	ResultCount = 0;
	int j;
	for (int i = 0; i < M; i++) {
		cin >> Input;
		Current = Root;
		Check = true;
		for (j = 0; Input[j] != 0; j++) { // 1. 위치 찾아가기
			if (Current->Next[Input[j] - 'a'] == nullptr) {
				Check = false;
				break;
			}
			Current = Current->Next[Input[j] - 'a'];
		}
		if (!Check)
			continue;
		// strcmp(Input, Current->Name);
		for (j = 0; Input[j] != 0; j++) { // 2. 저장된 값 비교
			if (Input[j] != 0 && Current->Name[j] != Input[j]) {
				Check = false;
				break;
			}
		}
		if (!Check)
			continue;

		//strcpy(Result[ResultCount], Input);
		_strcpy(Result[ResultCount], Input);
		/*for (j = 0; Input[j] != 0; j++) {
			Result[ResultCount][j] = Input[j];
		}*/
		ResultCount++;
	}

	qsort((void*)Result, ResultCount, sizeof(Result[0]), _strcmp);
}

int main()
{
	Init();
	Search();
	cout << ResultCount;
	for (int i = 0; i < ResultCount; i++) {
		cout << endl;
		cout << Result[i];
	}

	delete[] Root;
	return 0;
}