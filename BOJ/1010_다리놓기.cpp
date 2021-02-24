#include <cmath>
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;


int pas[31][31] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pas[0][0] = 1;
	for (int i = 0; i <= 30; i++) {
		pas[i][0] = 1;
		pas[i][i] = 1;
	}

	for (int i = 2; i <= 30; i++) {
		for (int j = 1; j < i; j++) {
			pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
		}
	}




	int testCase, n, m;
	cin >> testCase;
	while (testCase--) {
		cin >> m >> n;
		cout << pas[n][m] << endl;
	}

	return 0;
}
