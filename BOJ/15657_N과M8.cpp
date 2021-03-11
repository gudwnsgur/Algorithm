#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<int> arr, res;

void dfs(int length, int n, int m) {
	if (length == m) {
		for (int i = 0; i < length; i++) cout << res[i] << ' ';
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (length == 0 || (length != 0 && res[length - 1] <= arr[i])) {
			res[length] = arr[i];
			dfs(length + 1, n, m);
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

	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	dfs(0, n, m);
	return 0;
}
