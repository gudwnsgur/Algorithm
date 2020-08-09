#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	vector<pair<int, int>> time;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		time.push_back(make_pair(s, e));
	}
	sort(time.begin(), time.end(), cmp);

	int curTime = time[0].second;
	int result = 1;

	for (int i = 1; i < time.size(); i++) {
		if (curTime <= time[i].first) {
			result++;
			curTime = time[i].second;
		}
	}

	cout << result << endl;
	return 0;
}