#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<vector<int>> adj;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // cost, node
int inf = 987654321;

void dijkstra(int n) {
	while (!pq.empty()) {
		int node = pq.top().second;
		pq.pop();

		for (int i = 2; i <= n; i++) {
			if (node == i) continue;
			if (dist[i] > dist[node] + adj[node][i]) {
				dist[i] = dist[node] + adj[node][i];
				pq.push({ dist[i], i });
			}
		}
	}
	return;
}
void initialize(int n) {
	for (int i = 1; i <= n; i++) adj[i][i] = 0;
	for (int i = 2; i <= n; i++) {
		dist[i] = adj[1][i];
		if (dist[i] != inf) pq.push({ dist[i], i });
	}
	return;
}

int solution(int N, vector<vector<int>> road, int K) {
	int answer = 0, n = N;
	adj = vector<vector<int>>(N + 1, vector<int>(N + 1, inf));
	dist = vector<int>(N + 1);
	dist[1] = 0;

	for (int i = 0; i < road.size(); i++) {
		adj[road[i][0]][road[i][1]] = min(adj[road[i][0]][road[i][1]], road[i][2]);
		adj[road[i][1]][road[i][0]] = min(adj[road[i][1]][road[i][0]], road[i][2]);
	}
	initialize(N);
	dijkstra(N);

	for (int i = 1; i <= N; i++) cout << dist[i] << ' ';

	for (int i = 1; i <= N; i++) if (dist[i] <= K) answer++;
	return answer;
}


int main() {
	solution(5, { {1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2} }, 3);
	return 0;
}