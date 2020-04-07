#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define NodeMAX 1001
bool visited[NodeMAX]{ false , };
vector<int> graph[NodeMAX];

void dfs(int v, int n) {
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		if (!visited[graph[v][i]]) {
			dfs(graph[v][i], n);
		}
	}
}

int main() {
	int n, v, result = 0;
	cin >> n >> v;

	for (int i = 0; i < v; i++) {
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	dfs(1, n);
	for (int i = 2; i <= n; i++) {
		if (visited[i]) result++;
	}
	cout << result;
	return 0;
}