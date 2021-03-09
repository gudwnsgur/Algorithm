#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#define endl '\n'
using namespace std;

int n, m;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<vector<char>> room;
vector<vector<bool>> visited;
map<pair<int, int>, int> exit_;

pair<int, int> SG;
vector<pair<int, int>> fire;

void findFireDist(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {x, y}, 1 });
	visited[x][y] = true;

	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second;
		int curCnt = q.front().second;

		if (exit_.find({ curX,curY }) != exit_.end()) {
			exit_.find({ curX, curY })->second =
				min(exit_.find({ curX,curY })->second, curCnt);
		}
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i], ny = curY + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (room[nx][ny] == '#') continue;

			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ {nx, ny} , curCnt + 1 });
			}

		}
		q.pop();
	}
}

int solve() {
	int res = 1000 * 1000 + 1;
	queue<pair<pair<int, int>, int>> q;
	q.push({ { SG.first, SG.second}, 1 });
	visited[SG.first][SG.second] = true;

	while (!q.empty()) {
		int curX = q.front().first.first, curY = q.front().first.second;
		int curCnt = q.front().second;

		if (exit_.find({ curX,curY }) != exit_.end()) {
			if (exit_.find({ curX, curY })->second > curCnt) {
				res = min(res, curCnt);
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = curX + dx[i], ny = curY + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (room[nx][ny] == '#' || room[nx][ny] == '*') continue;

			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ { nx, ny } , curCnt + 1 });
			}

		}
		q.pop();
	}

	return res;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> m >> n;
		room = vector<vector<char>>(n, vector<char>(m));
		fire.clear();


		exit_.clear();

		string str;
		for (int i = 0; i < n; i++) {
			cin >> str;
			for (int j = 0; j < m; j++) {
				room[i][j] = str[j];
				if (room[i][j] == '*') fire.push_back({ i,j });
				else if (room[i][j] == '@') SG = { i,j };
				else if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && room[i][j] == '.') {
					exit_.insert({ { i,j }, 1000 * 1000 + 1 });
				}
			}
		}

		if (SG.first == 0 || SG.first == n - 1 || SG.second == 0 || SG.second == m - 1) {
			cout << 1 << endl;
			continue;
		}

		if (exit_.empty()) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		for (int i = 0; i < fire.size(); i++) {
			visited = vector<vector<bool>>(n, vector<bool>(m, false));
			findFireDist(fire[i].first, fire[i].second);
		}
		visited = vector<vector<bool>>(n, vector<bool>(m, false));

		int result = solve();
		if (result < 1000 * 1000 + 1) cout << result << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}

