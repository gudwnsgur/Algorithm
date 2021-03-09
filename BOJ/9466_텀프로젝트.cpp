#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, cnt;
vector<int> arr;
vector<bool> visited, res;

void dfs(int cur) {
	// O(n) : 노드를 한번씩 순회
	if (visited[cur]) return;
	visited[cur] = true;


	if (!visited[arr[cur]]) dfs(arr[cur]);

	else if (!res[arr[cur]]) {
		cnt++;
		for (int i = arr[cur]; i != cur; i = arr[i]) cnt++;
	} 
	// visited = true , res = false 
	// 방금 방문했으나 cylce을 세지 않은 node 집합

	res[cur] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		cnt = 0;

		cin >> n;
		arr = vector<int>(n + 1);
		res = vector<bool>(n + 1, false);
		visited = vector<bool>(n + 1, false);

		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= n; i++) dfs(i);

		cout << n - cnt << endl;
	}
	return 0;
}

