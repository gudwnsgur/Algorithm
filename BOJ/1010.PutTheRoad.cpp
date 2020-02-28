#include <iostream>
using namespace std;

int combination(int n, int r) {
	if (r == 1) return n;
	if (n == r) return 1;
	return combination(n - 1, r) + combination(n - 1, r - 1);
}

int main() {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int N, M;
		cin >> N >> M;
		cout << combination(M, N) << endl;
	}
	return 0;
}