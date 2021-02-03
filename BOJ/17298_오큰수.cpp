#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define endl '\n'
using namespace std;


void solve(int n) {
	vector<int> input(n), res(n);
	stack<int> s;
	for (int i = 0; i < n; i++) cin >> input[i];
	res[n - 1] = -1;
	s.push(input[n - 1]);

	for (int i = n - 2; i >= 0; i--) {
		while (!s.empty() && input[i] >= s.top()) s.pop();
		res[i] = s.empty() ? -1 : s.top();
		s.push(input[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}cout << endl;
	return;
}

int main() {
	int n;
	cin >> n;
	solve(n);
	return 0;
}
