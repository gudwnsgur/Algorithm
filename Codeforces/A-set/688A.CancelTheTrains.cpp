#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;


int solve(int n, int m) {
	int res = 0;
	vector<int> row(n), column(m);
	for (int i = 0; i < n; i++) cin >> row[i];
	for (int i = 0; i < m; i++) cin >> column[i];

	for (int i = 0, j = 0; i < n && j < m; i++, j++) {
		if (row[i] == column[j]) res++;
		else if (row[i] > column[j]) i--;
		else j--;
	}
	return res;
}

int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n, m;
		cin >> n >> m;
		cout << solve(n, m) << endl;
	}
	return 0;
}
