#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define endl '\n'
using namespace std;

vector<vector<char>> star(1025, vector<char>(1025, ' '));;

void rec(int x, int y, int length) {
	if (length == 1) {
		star[x][y] = '*';
		return;
	}
	rec(x, y, length/2);
	rec(x + length/2, y, length / 2);
	rec(x, y + length / 2, length / 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	rec(0, 0, pow(2, n));

	for (int i = 0; i < pow(2,n); i++) {
		for (int j = 0, k = pow(2, n) - i - 1; k >= 0; j++, k--) {
			cout << star[i][j];
		}
		cout << endl;
	}
	return 0;
}

