#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

bool visited[1001] = { false, };
bool graph[1001][1001] = { false, };
int cnt = 0;

void dfs(int v, int n) {
	for (int i = 1; i <= n; i++) {
		if (graph[v][i] && !visited[i]) {
			visited[i] = true;
			dfs(i, n);
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
		graph[x][y] = true;
		graph[y][x] = true;
	}

	for (int i = 1; i <= v; i++) {
		if (!visited[i]) {
			cnt++;
			visited[i] = true;
			dfs(i, v);
		}
	}
	cout << cnt << endl;
	return 0;
}