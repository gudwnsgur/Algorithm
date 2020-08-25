#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main() {
	int n, sum = 0;
	cin >> n;
	vector<int> v(n);
	vector<pair<int, int>> mode;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	double avg = (double)sum / n;
	sort(v.begin(), v.end());

	mode.push_back(make_pair(1, v[0]));
	for (int i = 1; i < (int)v.size(); i++) {
		if (v[i] == mode.back().second) mode.back().first++;
		else mode.push_back(make_pair(1, v[i]));
	}

	sort(mode.begin(), mode.end(), cmp);
	
	
	cout << round(avg) << endl;
	cout << v[v.size() / 2] << endl;
	cout << (mode.size() > 1 ? (mode[0].first == mode[1].first ? mode[1].second : mode[0].second) : mode[0].second) << endl;
	cout << v[v.size() - 1] - v[0] << endl;


	return 0;
}