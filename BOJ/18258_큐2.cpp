#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	cin >> n;
	queue<int> q;
	string op;


	for (int i = 0; i < n; i++) {
		cin >> op;
		if (op == "push") {
			cin >> num;
			q.push(num);
		}
		else if (op == "pop") {
			if (q.empty()) cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (op == "size") cout << q.size() << endl;
		else if (op == "empty") cout << q.empty() << endl;
		else if (op == "front") cout << (q.empty() ? -1 : q.front()) << endl;
		else cout << (q.empty() ? -1 : q.back()) << endl;
	}
	return 0;
}

