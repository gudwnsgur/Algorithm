#include <string>
#include <vector>
#include <iostream>
using namespace std;

char boards[30][30];
bool erasing[30][30];

int solution(int m, int n, vector<string> board) {
	int answer = 0, erased;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			boards[i][j] = board[i][j];
			erasing[i][j] = false;
		}
	}
	do {
		erased = 0;
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (board[i][j] != 'X' && // z가 아니면
					board[i][j] == board[i][j + 1] &&
					board[i][j] == board[i + 1][j] &&
					board[i][j] == board[i + 1][j + 1]) {
					erasing[i][j] = erasing[i][j + 1] = erasing[i + 1][j] = erasing[i + 1][j + 1] = true;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (erasing[i][j]) erased++;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = m - 1; j >= 0; j--) {
				if (board[j][i] == 'X' || erasing[j][i]) {
					int x = j;
					bool done = false;
					while (x--) {
						if (!erasing[x][i] && board[x][i] != 'X' && !done) {
							board[j][i] = board[x][i];
							board[x][i] = 'X';
							done = true;
						}
					}
					if (x == -1 && !done) board[j][i] = 'X';
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				erasing[i][j] = false;
			}
		}

		answer += erased;
	} while (erased);
	return answer;
}

int main() {
	vector<string> v;
	string str = "AAAAAA";
	v.push_back(str);
	str = "BBAATB";
	v.push_back(str);
	str = "BBAATB";
	v.push_back(str);
	str = "JJJTAA";
	v.push_back(str);
	str = "JJJTAA";
	v.push_back(str);

	cout << solution(5, 6, v);
	return 0;
}