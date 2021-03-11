#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int n;
int blue = 0, white = 0;
vector<vector<int>> paper;

void rec(int x, int y, int N, int color) {
	if (N == 1) {
		color ? blue++ : white++;
		return;
	}
	bool pos = true;
	for (int i = x; i < x+N; i++) {
		if (!pos) break;
		for (int j = y; j < y + N; j++) {
			if (paper[i][j] != color) {
				pos = false;
				break;
			}
		}
	}
	if (pos) {
		color ? blue++ : white++;
		return;
	}
	rec(x, y, N / 2, paper[x][y]);
	rec(x + N / 2, y, N / 2, paper[x + N / 2][y]);
	rec(x, y + N / 2, N / 2, paper[x][y + N / 2]);
	rec(x + N / 2, y + N / 2, N / 2, paper[x + N / 2][y + N / 2]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	paper = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	rec(0, 0, n, paper[0][0]);
	cout << white << endl << blue << endl;
	return 0;
}
