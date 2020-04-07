#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define NodeMAX 1001
#define VertexMAX 10001
vector<int> graph[NodeMAX];	
// 비용이 있는 graph : vector<pair<int, int>> graph[NodeSize]

bool visited[1001]{ false, };

void dfs(int v, int n) {
	visited[v] = true;
	cout << v << ' ';
	for (int i = 0; i < graph[v].size(); i++) {
		if (!visited[graph[v][i]]) {
			dfs(graph[v][i], n);
		}
	}
}

void bfs(int v, int n) {
	queue<int> q;
	cout << v << ' ';
	visited[v] = true;

	q.push(v);
	while (!q.empty()) {
		v = q.front();
		for (int i = 0; i < graph[v].size(); i++) {
			if(!visited[graph[v][i]]) {
				visited[graph[v][i]] = true;
				q.push(graph[v][i]);
				cout << graph[v][i] << ' ';
			}
		}
		q.pop();
	}
}

int main() {
	int n, m, v; // G(n,m), 시작(v)
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e; 
		graph[s].push_back(e); // 노드 s 리스트에 e 추가
		graph[e].push_back(s); // 양방향이므로 두군데에 추가
	} // 간선 초기화

	for (int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());

	dfs(v, n);	// DFS
	cout << endl;
	for (int i = 1; i <= n; i++) visited[i] = false; // visited 초기화

	bfs(v, n); // BFS

	// 인접리스트 출력 코드
	/*
	for (int i = 1; i <= n; i++) {
		cout << i << ": ";
		for (int j = 0; j < graph[i].size(); j++) {
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	return 0;
}