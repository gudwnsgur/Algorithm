#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define X first
#define Y second
#define endl '\n'
using namespace std;


int n, m;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<vector<int>> map;
vector<vector<bool>> bVisited, nonBVisited;
queue<pair<pair<int, int>, pair<bool, int>>> q;
// {x, y}, {broke, cnt}

int bfs() {

	while (!q.empty()) {
		int curX = q.front().X.X, curY = q.front().X.Y, curCnt = q.front().Y.Y;
		bool broke = q.front().Y.X;

		if (curX == n - 1 && curY == m - 1) {
			return curCnt;
		}

		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i], ny = curY + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (broke) {
				// 부시고 온놈
				if (!nonBVisited[nx][ny] && !bVisited[nx][ny] && !map[nx][ny]) {
					bVisited[nx][ny] = true;
					q.push({ {nx, ny}, {true, curCnt + 1} });
				}
			}
			else {
				// 안부시고 온놈
				if (!nonBVisited[nx][ny]) {
					if (map[nx][ny]) {
						bVisited[nx][ny] = true;
						q.push({ {nx, ny}, {true, curCnt + 1} });
					}
					else {
						nonBVisited[nx][ny] = true;
						q.push({ { nx, ny },{ false, curCnt + 1 } });
					}
				}
			}

		}
		q.pop();
	}
	return -1;
}

int main() {
	string str;
	cin >> n >> m;
	map = vector<vector<int>>(n, vector<int>(m));
	bVisited = vector<vector<bool>>(n, vector<bool>(m, false));
	nonBVisited = vector<vector<bool>>(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - 48;
		}
	}
	q.push({ {0, 0}, {false, 1} });
	nonBVisited[0][0] = true;

	cout << bfs() << endl;
	return 0;
}
