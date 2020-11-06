#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<vector<int>> graph;
vector<int> node;
vector<bool> visited;

bool compare(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}
int getParent(int cnt) {
	if (node[cnt] == cnt) return cnt;
	return node[cnt] = getParent(node[cnt]);
}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) node[b] = a;
	else node[a] = b;
}
int findUnion(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b ? 1 : 0;
}

int main() {
	int n, m;
	cin >> n >> m;
	node = vector<int>(n + 1);

	for (int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		graph.push_back({ s,e,w });
	}
	sort(graph.begin(), graph.end(), compare);

	int testCase;
	cin >> testCase;
	while (testCase--) {
		visited = vector<bool>(n + 1, false);
		int x, y, minTemp = 0, nodeCnt = 0;
		cin >> x >> y;
		visited[x] = true;
		for (int i = 1; i <= n; i++) node[i] = i;

		for (int i = 0; i < graph.size(); i++) {
			if (getParent(x) == getParent(y)) break;// Connected
			if (!findUnion(graph[i][0], graph[i][1])) {
				minTemp = graph[i][2];
				unionParent(graph[i][0], graph[i][1]);
				visited[graph[i][0]] = true;
				visited[graph[i][1]] = true;
			}
		}
		for (int i = 1; i <= n; i++) if (visited[i]) nodeCnt++;
		if (getParent(x) != getParent(y)) cout << -1 << endl;
		else cout << minTemp << ' ' << nodeCnt << endl;
	}
	return 0;
}