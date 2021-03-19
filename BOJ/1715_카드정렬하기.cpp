#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <functional>
using namespace std;

int n, num, result = 0;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		pq.push(num);
	}
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}

	while (!pq.empty()) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		result += a + b;
		if (pq.empty()) break;
		pq.push(a + b);
	}
	cout << result << endl;
	return 0;
}

