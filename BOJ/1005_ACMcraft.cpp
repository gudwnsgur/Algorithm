// 시간 초과
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#define endl '\n'
using namespace std;

int x, y; // x -> y
int endPoint, maxTime = 0;
bool visited[1001] = { false, };
int time[1001] = { 0, }; // i번째 건물을 짓는 소요시간

void dfs(int v, int cur, const vector<int> *graph) {
	if (!graph[cur].size()) {
		int sum = 0;
		for (int i = 1; i <= v; i++) 
			sum += visited[i] * time[i];
		maxTime = max(maxTime, sum);
		return;
	}
	for (int i = 0; i < graph[cur].size(); i++) {
		if (!visited[graph[cur][i]]) {
			visited[graph[cur][i]] = true;
			dfs(v, graph[cur][i], graph);
			visited[graph[cur][i]] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; t++) {
		int v, e; // vertex, edges
		cin >> v >> e;

		for (int i = 1; i <= v; i++) {
			cin >> time[i];
			visited[i] = false;
		}

		vector<int> graph[1001];
		for (int i = 0; i < e; i++) {
			cin >> x >> y;
			graph[y].push_back(x);
		}
		maxTime = 0;
		cin >> endPoint;
		visited[endPoint]++;
		dfs(v, endPoint, graph);
		cout << maxTime << endl;
	}
	return 0;
} 
