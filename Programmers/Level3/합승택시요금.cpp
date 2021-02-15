#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 20000000
using namespace std;

vector<vector<int>> graph;
vector<int> distSum;
int N;

void findDist(int s) {
	vector<int> dist(N + 1, MAX);
	vector<bool> visited(N + 1, false);


	for (int i = 1; i <= N; i++) {
		dist[i] = graph[s][i];
	}
	dist[s] = 0;
	visited[s] = true;
	int node = s;

	for (int i = 1; i < N; i++) {
		int minDist = MAX;
		for (int j = 1; j <= N; j++) {
			if (!visited[j] && minDist > dist[j]) {
				node = j;
				minDist = dist[j];
			}
		}
		
		for (int j = 1; j <= N; j++) {
			if (!visited[j] && graph[node][j] != MAX) {
				dist[j] = min(dist[j], dist[node] + graph[node][j]);
			}
		}
		visited[node] = true;
	}

	for (int i = 1; i <= N; i++) {
		distSum[i] += dist[i];
	}
	return;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	N = n;
	graph = vector<vector<int>>(n + 1, vector<int>(n + 1, MAX));
	distSum = vector<int>(n + 1, 0);
	int answer = 0;

	for (int i = 0; i < fares.size(); i++) {
		graph[fares[i][0]][fares[i][1]] = fares[i][2];
		graph[fares[i][1]][fares[i][0]] = fares[i][2];
	}

	findDist(s);
	findDist(a);
	findDist(b);
	
	int minDist = MAX;
	for (int i = 1; i <= n; i++) {
		if (distSum[i] < minDist) {
			minDist = distSum[i];
		}
	}
	return minDist;
}
