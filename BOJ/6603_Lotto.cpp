#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[14] = { 0, };
bool visited[14] = { false, };

void dfs(int length, int n, vector<int> v) {
	if (length == 6) {
		for (int i = 0; i < 6; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (!visited[i] && arr[length-1] < v[i]  ) {
			visited[i] = true;
			arr[length] = v[i];
			dfs(length + 1, n, v);
			visited[i] = false;
		}
	}

}

int main() {
	while (1) {
		int n, num;
		vector<int> v;
		cin >> n;
		if (!n) break;

		for (int i = 0; i < n; i++) {
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		dfs(0, n, v);
		cout << endl;
	}
	return 0;
}