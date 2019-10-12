#include <string>
#include <cstring>
#include <vector>

using namespace std;

int Length;

int solution(vector<string> board) {
	Length = board.size();
	register int i,j, Temp;
	bool Flag;
	for (register int k = Length - 1; k > 1; k--) {
		for (i = 0; i + k < Length; i++) {
			for (j = 0; j + k < Length; j++) {
				if (k % 2 == 0) { // 짝수 이면
					if (board[i][j] == board[i][j + k] && board[i][j] == board[i + k][j] && board[i][j] == board[i + k][j + k]) { // 꼭지점 체크
						int x[4] = { i,i,i + k,i + k };
						int y[4] = { j,j + k,j,j + k };
						Flag = true;
						for (Temp = 1; Temp < k/2 +1; Temp++) {
							if (board[i][j] != board[x[0]+ Temp][y[0]+ Temp]) {
								Flag = false;
								break;
							}
							if (board[i][j] != board[x[1]+ Temp][y[1]- Temp]) {
								Flag = false;
								break;
							}
							if (board[i][j] != board[x[2]- Temp][y[2]+ Temp]) {
								Flag = false;
								break;
							}
							if (board[i][j] != board[x[3]- Temp][y[3]- Temp]) {
								Flag = false;
								break;
							}
						}
						if (Flag) {
							return k + 1;
						}
					}
				}
			}
		}
	}

	return 0;
}
