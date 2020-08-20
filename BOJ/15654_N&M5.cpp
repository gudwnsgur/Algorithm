#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define MAX 9
using namespace std;

int arr[MAX];
bool visited[MAX] = { false, };
vector<int> v;
int n, m;

void dfs(int length) {
	if (length == m) {
		for (int i = 0; i < m; i++) cout << arr[i]<< ' ';
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			arr[length] = v[i];
			visited[i] = true;
			dfs(length+1);
			visited[i] = false;
		}
	}
	return;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int number;
	cin >> n >> m;
	for (int i = 0; i < n; i++)  {
		cin >> number;
		v.push_back(number);
	}
	sort(v.begin(), v.end());
	dfs(0);
	return 0;
}