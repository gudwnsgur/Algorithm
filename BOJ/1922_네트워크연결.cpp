#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

int n, m, result=0;
int node[1001] = { 0, };
vector<vector<int>> graph;

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

	if (a<b) node[b] = a;
	else node[a] = b;
}
int findUnion(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	return a == b ? 1 : 0;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) node[i] = i;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph.push_back({u,v,w});
	}

	sort(graph.begin(), graph.end(), compare);
	for (int i = 0; i < graph.size(); i++) {
		if (!findUnion(graph[i][0], graph[i][1])) {
			result += graph[i][2];
			unionParent(graph[i][0], graph[i][1]);
		}
	}
	cout << result << endl;
	return 0;
}