#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#define endl '\n'
#define ll long long
using namespace std;


bool compare(pair<ll, int> a, pair<ll, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
int main() {
	int n;
	ll num;

	cin >> n;
	map<ll, int> m;
	vector<ll> v;
	vector<pair<ll, int>> result;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (m.find(num) == m.end()) {
			m.insert({ num, 1 });
			v.push_back(num);
		}
		else m.find(num)->second++;
	}

	for (int i = 0; i < v.size(); i++) {
		result.push_back({ v[i], m.find(v[i])->second });
	}

	sort(result.begin(), result.end(), compare);
	cout << result[0].first << endl;
	return 0;
}

