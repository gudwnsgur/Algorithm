#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

int n, m;
int cnt = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<vector<int>> map, melted;
vector<vector<bool>> visited;


bool isPossible() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) cnt++;
		}
	}
	return (cnt != 0 && cnt != n*m);
}

void melt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j]) continue;
			int cnt = 0;

			for (int k = 0; k < 4; k++) {
				int nx = dx[k] + i, ny = dy[k] + j;
				if (nx < 0 || nx >= n || ny < 0 || ny >= m);
				else if(!map[nx][ny]) cnt++;
			}

			melted[i][j] = min(map[i][j], cnt);

		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] -= melted[i][j];
		}
	}
	return;
}
bool solve() {
	visited = vector<vector<bool>>(n, vector<bool>(m, false));
	queue<pair<int, int>> q;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] && !visited[i][j]) {
				visited[i][j] = true;
				q.push({ i, j });
				cnt++;
				while (!q.empty()) {
					for (int k = 0; k < 4; k++) {
						int nx = dx[k] + q.front().first, ny = dy[k] + q.front().second;
						if (nx < 0 || nx >= n || ny < 0 || ny >= m);
						else if(map[nx][ny] && !visited[nx][ny]){
							visited[nx][ny] = true;
							q.push({ nx, ny });
						}
					}
					q.pop();
				}
			}
		}
	}
	if (cnt >= 2) return true;
	return false;
}

int main (){
	cin >> n >> m;

	map = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	while (true) {

		if (!isPossible()) {
			cout << 0 << endl;
			return 0;
		}

		melted = vector<vector<int>>(n, vector<int>(m, 0));
		melt();
		cnt++;

		if (solve()) {
			cout << cnt << endl;
			return 0;
		}
	}
	return 0;
}

