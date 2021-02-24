#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define X first
#define Y second
#define endl '\n'
using namespace std;

int n, m;
int result = -1;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<vector<int>> map;
vector<vector<int>> tmp;
vector<vector<bool>> visited;
vector<pair<int, int>> virus;
vector<pair<int, int>> zero;
pair<int, int> wall[3];
queue<pair<int, int>> q;

void bfs() {
	int curRes = 0;
	visited = vector<vector<bool>>(n, vector<bool>(m, false));
	tmp = map;

	for (int i = 0; i < 3; i++) {
		tmp[wall[i].X][wall[i].Y] = 1;
	}

	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
		visited[virus[i].X][virus[i].Y] = true;
	}

	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + q.front().X, ny = dy[i] + q.front().Y;
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (!visited[nx][ny] && tmp[nx][ny] == 0) {
				visited[nx][ny] = true;
				tmp[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
		q.pop();
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) curRes++;
		}
	}
	result = max(result, curRes);
	return;
}

int main () {
	cin >> n >> m;
	map = vector<vector<int>>(n, vector<int>(m));


