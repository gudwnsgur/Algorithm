#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#define endl '\n'
using namespace std;

vector<bool> visited;
vector<int> arr, res;
set<string> s;

void dfs(int length, int n, int m) {
	if (length == m) {
		string str = "";
		for (int i = 0; i < res.size(); i++) str.push_back(res[i]+48);
		if (s.find(str) != s.end()) return;

		s.insert(str);
		for (int i = 0; i < length; i++) cout << res[i] << ' ';
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			res[length] = arr[i];
			dfs(length + 1, n, m);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	arr = vector<int>(n);
	res = vector<int>(m);
	visited = vector<bool>(n, false);

	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	dfs(0, n, m);
	return 0;
}
