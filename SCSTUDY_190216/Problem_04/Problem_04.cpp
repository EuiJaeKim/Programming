#include <iostream>
#include <vector>

using namespace std;

int N, B, C;
vector<int> Student;

void Init();
long long Solve();

int main()
{
	Init();
	cout << Solve();
	return 0;
}

void Init()
{
	int Temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Temp;
		Student.push_back(Temp);
	}
	cin >> B >> C;
}

long long Solve()
{
	long long Count = 0;
	long long Temp;
	for (int i = 0; i < N; i++) {

		if (Student[i] - B > 0) {
			Temp = (Student[i] - B) / C;
			Count += Temp;
			if (Student[i] - (B + (Temp * C)) > 0)
				Count++;
		}
		Count++;

	}
	return Count;
}