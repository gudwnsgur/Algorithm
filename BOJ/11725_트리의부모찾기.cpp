#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int n, u, v;
vector<vector<int>> tree;
vector<bool> visited;
vector<int> parent;

void dfs(int node) {
	for (int i = 0; i < tree[node].size(); i++) {
		if (!visited[tree[node][i]]) {
			parent[tree[node][i]] = node;
			visited[tree[node][i]] = true;
			dfs(tree[node][i]);
		}
	}
	return;
}
int main() {
	cin >> n;
	tree = vector<vector<int>>(n + 1);
	visited = vector<bool>(n + 1, false);
	parent = vector<int>(n + 1);

	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	visited[1] = true;
	dfs(1);
	for (int i = 2; i <= n; i++) cout << parent[i] << endl;
	return 0;
}