#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int solution(int n, int m, int r, int c) {
	return max(n - r, r - 1) + max(m - c, c - 1);
}

int main () {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n, m, r, c;
		cin >> n >> m >> r >> c;
		cout << solution(n, m, r, c) << endl;
	}
	return 0;
}
