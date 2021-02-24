#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define X first
#define Y second
#define endl '\n'
using namespace std;

int n, m, h;
int dx[6] = { 1, -1, 0, 0, 0 ,0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

vector<vector<vector<int>>> map;
vector<vector<vector<bool>>> visited;
queue<pair<pair<int, int>, pair<int, int>>> q;

int bfs() {
	int result = 0;
	while (!q.empty()) {
		int curX = q.front().X.X, curY = q.front().X.Y, curZ = q.front().Y.X;
		int curDay = q.front().Y.Y;


		for (int i = 0; i < 6; i++) {
			int nx = dx[i] + curX, ny = dy[i] + curY, nz = dz[i] + curZ;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (!visited[nx][ny][nz] && map[nx][ny][nz] == 0) {
				visited[nx][ny][nz] = true;
				map[nx][ny][nz] = 1;
				q.push({ {nx, ny}, {nz, curDay + 1} });
				result = max(result, curDay + 1);
			}
		}
		q.pop();
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < h; k++) {
				if (map[i][j][k] == 0) return -1;
			}
		}
	}
	return result;
}

int main() {
	cin >> m >> n >> h;
	map = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(h)));
	visited = vector<vector<vector<bool>>>(n, vector<vector<bool>>(m, vector<bool>(h, false)));

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({ {i,j}, {k , 0} });
					visited[i][j][k] = true;
				}
			}
		}
	}
	cout << bfs() << endl;
	return 0;
}
