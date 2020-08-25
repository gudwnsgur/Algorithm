#include <iostream>
#include <vector>
using namespace std;


int sudoku[9][9] = { 0, };
vector<int> v;
bool visited[81] = { false, };
bool finished = false;

bool promising(int num, int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[x][i] == num) return false;
		if (sudoku[i][y] == num) return false;
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (x / 3 == i / 3 && y / 3 == j / 3) {
				if (sudoku[i][j] == num) return false;
			}
		}
	}
	return true;
}

void printSudoku() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << ' ';
		}
		cout << endl;
	}
}

void dfs(int length, int n) {
	if (finished) return;
	if (length == n) {
		finished = true;
		printSudoku();
		return;
	}

	if (!visited[length]) {
		int x = v[length] / 9, y = v[length] % 9;

		for (int i = 1; i <= 9; i++) {
			if (promising(i, x, y)) {
				visited[length] = true;
				sudoku[x][y] = i;
				dfs(length + 1, n);
				visited[length] = false;
				sudoku[x][y] = 0;
			}
		}
	}

}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0)
				v.push_back(i * 9 + j);
		}
	}
	dfs(0, v.size());
	return 0;
}