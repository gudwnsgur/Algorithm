#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

int n;
int res = 200;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<pair<int, pair<int, int>>> edge;

int main() {
	cin >> n;
	map = vector<vector<int>>(n, vector<int>(n));
	visited = vector<vector<bool>>(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	queue<pair<int, int>> q;
	int island = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] & map[i][j]) {
				island++;
				q.push({ i, j });
				visited[i][j] = true;
				while (!q.empty()) {
					for (int k = 0; k < 4; k++) {
						int nx = dx[k] + q.front().first, ny = dy[k] + q.front().second;
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						
						if (!map[nx][ny]) edge.push_back({ island,{ q.front().first, q.front().second } });
						else if (!visited[nx][ny]) {
							visited[nx][ny] = true;
							q.push({ nx, ny });
						}

					}
					q.pop();
				}
			}
		}
	}
	edge.erase(unique(edge.begin(), edge.end()), edge.end());
	for (int i = 0; i < edge.size() - 1; i++) {
		for (int j = i + 1; j < edge.size(); j++) {
			if (edge[i].first != edge[j].first) {
				res = min(res, abs(edge[i].second.first - edge[j].second.first) 
					+ abs(edge[i].second.second - edge[j].second.second) -1);
			}
			if (res == 1) {
				cout << res << endl;
				return 0;
			}
		}
	}
	cout << res << endl;
	return 0;
}
