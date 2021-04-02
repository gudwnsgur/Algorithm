#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define endl '\n'
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	deque<int> dq;
	for (int i = 0; i < n; i++) cin >> v[i];

	reverse(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		if (v[i - 1] == 1) dq.push_front(i);
		else if (v[i - 1] == 2) {
			int first = dq.front();
			dq.pop_front();
			dq.push_front(i);
			dq.push_front(first);
		}
		else dq.push_back(i);
	}
	while (!dq.empty()) {
		cout << dq.front() << ' ';
		dq.pop_front();
	}cout << endl;

	return 0;
}
