#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

void solve(int n) {
	for (int i = 0, num = n * 2 + 2; i < n; i++, num += 2) cout << num << ' ';
	cout << endl;
	return;
}

int main() {
	int testCase, n;
	cin >> testCase;
	while (testCase--) {
		cin >> n;
		solve(n);
	}
	return 0;
}
