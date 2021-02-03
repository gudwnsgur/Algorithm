#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define endl '\n'
using namespace std;


void solve(int n) {
	int num;
	stack<int> s;
	queue<int> q;
	vector<char> res;
	for (int i = 0; i < n; i++) {
		cin >> num;
		q.push(num);
	}

	for (int i = 1; i <= n; i++) {
		res.push_back('+');
		s.push(i);
		while (!s.empty() && s.top() == q.front()) {
				s.pop();
				q.pop();
				res.push_back('-');
		}
	}

	if (q.empty()) {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << endl;
		}
		return;
	}
	cout << "NO" << endl;
	return;
}

int main() {
	int n;
	cin >> n;
	solve(n);
	return 0;
}

