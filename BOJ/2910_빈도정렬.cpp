#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#define endl '\n'
using namespace std;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.second == b.first.second) return a.second < b.second;
	return a.first.second > b.first.second;
}
int main() {
	int n, c, num;
	cin >> n >> c;

	map<int, int> m;
	vector<int> order;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (m.find(num) == m.end()) {
			order.push_back(num);
			m.insert({ num, 1 });
		}
		else m.find(num)->second++;
	}
	vector<pair<pair<int, int>, int>> result;
	for (int i = 0; i < order.size(); i++) {
		result.push_back({ {order[i], m.find(order[i])->second} , i });
	}
	sort(result.begin(), result.end(), compare);
	for (int i = 0; i < result.size(); i++) {
		while (result[i].first.second--) {
			cout << result[i].first.first << ' ';
		}
	}
	cout << endl;
	return 0;
}

