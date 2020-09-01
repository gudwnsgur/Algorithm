#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

bool visited[1001] = { false, };
vector<vector<int>> graph(1001); 
int cnt = 0;

void dfs(int v) {
	for (int i = 0; i < graph[v].size(); i++) {
		if (!visited[graph[v][i]]) {
			visited[graph[v][i]] = true;
			dfs(graph[v][i]);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 1; i <= v; i++) {
		if (!visited[i]) {
			cnt++;
			visited[i] = true;
			dfs(i);
		}
	}
	
	cout << cnt << endl;
	return 0;
}