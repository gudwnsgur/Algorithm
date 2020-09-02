#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#define endl '\n'
#define X front().first // index
#define Y front().second // 중요도
using namespace std;

int print(int n, int m) {
	queue<pair<int, int>> q;
	vector<int> v;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int priority;
		cin >> priority;
		q.push(make_pair(i, priority));
		v.push_back(priority);
	}

	sort(v.begin(), v.end(), greater<int>());
	int vIndex = 0;
	while (!q.empty()) {
		while (q.Y != v[vIndex]) {
			int x = q.X, y = q.Y;
			q.pop();
			q.push(make_pair(x, y));
		}
		if (q.X == m && q.Y == v[vIndex]) {
			return cnt;
		}
		vIndex++;
		q.pop();
		cnt++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int n, m;
		cin >> n >> m;
		cout << print(n, m) << endl;
	}
	return 0;
} 