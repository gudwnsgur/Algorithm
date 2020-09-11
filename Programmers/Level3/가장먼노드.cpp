#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int, int>> v; // cnt, node
bool visited[20001] = { false, };
bool graph[20001][20001] = { 0, };
int cnt = 1;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int solution(int n, vector<vector<int>> edge) {

	for (int i = 0; i < edge.size(); i++) {
		graph[edge[i][0]][edge[i][1]] = 1;
		graph[edge[i][1]][edge[i][0]] = 1;
	}
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int node = q.front();
			for (int j = 2; j <= n; j++) {
				if (!visited[j] && graph[node][j]) {
					visited[j] = true;
					v.push_back(make_pair(cnt, j));
					q.push(j);
				}
			}
			q.pop();
		}
		cnt++;
	}
	sort(v.begin(), v.end(), compare);
	int maxLength = v[0].first, result =1;
	for (int i = 1; i < v.size(); i++) {
		if (maxLength == v[i].first) result++;
	}

	return result;
}