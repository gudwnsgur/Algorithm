#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int inf = 0xfffffff;
vector<vector<int>> graph;
vector<int> dist;
bool visited[1001] = { false, };
int n, m;

void dijkstra(int src) {
	for (int i = 1; i <= n; i++) dist[i] = graph[src][i];
	visited[src] = true;
	int node = src;

	for (int i = 1; i < n; i++) {
		int minDist = inf;
		for (int j = 1; j <= n; j++) {
			if (!visited[j] && minDist > dist[j]) {
				node = j;
				minDist = dist[j];
			}
		}
		
		for (int j = 1; j <= n; j++) {
			if (!visited[j] && graph[node][j] != inf) {
				dist[j] = min(dist[j], dist[node] + graph[node][j]);
			}
		}
		visited[node] = true;
	}
	return;
}

int main() {
	int start, end;
	cin >> n >> m;
	graph = vector<vector<int>>(n + 1, vector<int>(n + 1, inf));
	dist = vector<int>(n + 1, inf);

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u][v] = min(graph[u][v], w);
		// 같은 경로에 더 짧은 거리가 입력될 수 있기 때문에
	}
	for (int i = 1; i <= n; i++) graph[i][i] = 0;

	cin >> start >> end;
	dijkstra(start);
	cout << dist[end] << endl;
	return 0;
}
