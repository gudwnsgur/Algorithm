#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define endl '\n'
using namespace std;

void solve(int n, int m) {
	vector<vector<int>> res;
	vector<int> tmp;
	map<int, vector<int>> map;
	int first, num;


	for (int i = 0; i < n; i++) {
		cin >> first;
		tmp.push_back(first);
		for (int j = 1; j < m; j++) {
			cin >> num;
			tmp.push_back(num);
		}
		map.insert({ first, tmp });
		tmp.clear();
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			if (map.find(num) != map.end()) {
				res.push_back(map.find(num)->second);
			}
		}
	}

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ' ';
		}cout << endl;
	}
	return;
}

int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n, m;
		cin >> n >> m;
		solve(n, m);
	}
	return 0;
}
