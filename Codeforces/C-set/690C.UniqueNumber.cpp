#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define endl '\n'
using namespace std;


void solve(int n) {
	stack<int> s;
	bool possible = false;
	for (int i = 9; i >= 1; i--) {
		if (n <= i) {
			possible = true;
			s.push(n);
			break;
		}
		n -= i;
		s.push(i);
	}

	if (!possible) {
		cout << -1 << endl;
		return;
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return ;
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
