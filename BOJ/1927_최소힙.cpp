#include <iostream>
#include <queue>
#include <functional>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>> pq;
	int n, op;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> op;
		if (!op) {
			if (pq.empty()) cout << "0" << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else pq.push(op);
	}
	return 0;
}