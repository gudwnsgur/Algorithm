#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1};

int main() {
	int m, n, k;
	cin >> m >> n >> k;
	vector<vector<bool>> map(m, vector<bool>(n, false));

	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			for (int l = y1; l < y2; l++) {
				map[l][j] = true;
			}
		}
	}

	vector<vector<bool>> visited(m, vector<bool>(n, false));
	queue<pair<int, int>> q;
	vector<int> result;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!map[i][j] && !visited[i][j]) {
				result.push_back(1);
				visited[i][j] = true;
				q.push({ i, j });

				while (!q.empty()) {
					for (int k = 0; k < 4; k++) {
						int nx = dx[k] + q.front().first, ny = dy[k] + q.front().second;
						if (nx < 0 || nx >= m || ny < 0 || ny >= n);
						else if(!map[nx][ny] && !visited[nx][ny]) {
							visited[nx][ny] = true;
							result.back()++;
							q.push({ nx, ny });
						}
					}
					q.pop();
				}
			}
		}
	}
	sort(result.begin(), result.end());

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) cout << result[i] << ' ';
	cout << endl;
	return 0;
}


