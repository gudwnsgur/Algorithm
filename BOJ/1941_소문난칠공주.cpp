#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define endl '\n'
#define X first
#define Y second
using namespace std;

int cnt = 0;
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
vector<vector<char>> loc(5, vector<char>(5));
vector<vector<bool>> visited(5, vector<bool>(5, false));
string str = "";
vector<pair<int, int>> seven(7);

bool promise() {
	int som = 0;
	for (int i = 0; i < 7; i++) {
		if (loc[seven[i].X][seven[i].Y] == 'S') som++;
	}
	if (som < 4) return false;

	// seven[7] 에 있는게 엮였나?
	int cur = 1;
	vector<vector<bool>> bfs_v(5, vector<bool>(5, false));
	vector<vector<bool>> bfs_map(5, vector<bool>(5, false));
	for (int i = 0; i < 7; i++) bfs_map[seven[i].X][seven[i].Y] = true;

	queue<pair<int, int>> q;
	q.push({ seven[0].X, seven[0].Y });
	bfs_v[seven[0].X][seven[0].Y] = true;

	while (!q.empty()) {
		int curX = q.front().X, curY = q.front().Y;
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i], ny = curY + dy[i];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (!bfs_map[nx][ny]) continue;

			if (!bfs_v[nx][ny]) {
				bfs_v[nx][ny] = true;
				cur++;
				q.push({ nx, ny });
			}
		}
		q.pop();
	}
	if (cur != 7) return false;
	return true;
}

void dfs(int length) {
	if (length == 7) {
		if (promise()) {
			cnt++;
		}
		return;
	}
	for (int i = 0; i < 25; i++) {
		if (!visited[i / 5][i % 5]) {
			if (length == 0 || (length != 0 && seven[length - 1].X * 5 + seven[length - 1].Y < i)) {
				visited[i / 5][i % 5] = true;
				seven[length] = { i / 5, i % 5 };
				dfs(length + 1);
				visited[i / 5][i % 5] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int i = 0; i < 5; i++) {
		cin >> str;
		for (int j = 0; j < 5; j++) {
			loc[i][j] = str[j];
		}
	}

	dfs(0);
	cout << cnt << endl;
	return 0;
}

