#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

int solve(int w, int h) {
	int result = 0;
	vector<vector<int>> map(h, vector<int>(w));
	vector<vector<bool>> visited(h, vector<bool>(w, false));
	queue<pair<int, int>> q;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] && !visited[i][j]) {
				visited[i][j] = true;
				result++;
				q.push({ i,j });
				while (!q.empty()) {
					for (int k = 0; k < 8; k++) {
						int nx = dx[k] + q.front().first, ny = dy[k] + q.front().second;
						if (nx < 0 || nx >= h || ny < 0 || ny >= w);
						else {
							if (map[nx][ny] && !visited[nx][ny]) {
								visited[nx][ny] = true;
								q.push({ nx, ny });
							}
						}
					}
					q.pop();
				}
			}
		}
	}


	return result;
}

int main() {
	int w, h;
	cin >> w >> h;
	while (w || h) {
		cout << solve(w, h) << endl;
		cin >> w >> h;
	}
	return 0;
}

