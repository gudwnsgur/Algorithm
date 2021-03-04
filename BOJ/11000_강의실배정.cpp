#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#define endl '\n'

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> time(n);
	for (int i = 0; i < n; i++) {
		cin >> time[i].first >> time[i].second;
	}

	sort(time.begin(), time.end(), compare);
	pq.push(time[0].second);

	for (int i = 1; i < n; i++) {
		if (pq.top() <= time[i].first) pq.pop();
		pq.push(time[i].second);
	}
	cout << pq.size() << endl;
	return 0;
}


