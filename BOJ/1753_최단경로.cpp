#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#define endl '\n'
using namespace std;

int dist[20001];
vector<pair<int, int>> adj[20001];
int n, m;
int inf = 0xfffffff;
bool visited[20001] = { false, };

void dijkstra(int src) 
{
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push(make_pair(dist[src], src));

	while (!pq.empty()) {
		int node = pq.top().second;
		pq.pop();
		visited[node] = true;
		for (int i = 0; i < adj[node].size(); i++) {
			if (dist[adj[node][i].first] > adj[node][i].second + dist[node]) {
				dist[adj[node][i].first] = adj[node][i].second + dist[node];
				if (!visited[adj[node][i].first]) {
					pq.push(make_pair(dist[adj[node][i].first], adj[node][i].first));
				}
			}
		}
	}
	return;
}

int main() {
	int start;
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v,w));
	}

	for (int i = 1; i <= n; i++) dist[i] = inf;
	dist[start] = 0;
	dijkstra(start);


	for (int i = 1; i <= n; i++) {
		if (dist[i] == inf) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}