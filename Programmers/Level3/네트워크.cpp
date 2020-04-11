#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define NodeMAX 200
bool visited[NodeMAX]{ false, };
vector<int> graph[NodeMAX];

void dfs(int v, int n) {
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		if (!visited[graph[v][i]]) {
			dfs(graph[v][i], n);
		}
	}
}

int solution(int n, vector<vector<int>> computers) 
{
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && computers[i][j]) {
				graph[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			answer++;
			dfs(i, n);
		}
	}
	return answer;
}
