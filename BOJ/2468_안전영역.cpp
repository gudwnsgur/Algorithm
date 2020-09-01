#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
#define endl '\n'
using namespace std;

int n;
int maxSafety = 1; // water=0 : maxSafety=1
int maxLength = 1;
int map[100][100] = { 0, };
bool visited[100][100] = { false, };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs(int water) {
	int localSafety = 0;
	bool one = false;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j] > water) {
				q.push(make_pair(i, j));
				visited[i][j] = true;
				localSafety++;
				while (!q.empty()) {
					int qSize = q.size();
					for (int k = 0; k < qSize; k++) {
						int x = q.front().first, y = q.front().second;
						for (int l = 0; l < 4; l++) {
							int nx = x + dx[l], ny = y + dy[l];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n);
							else if (visited[nx][ny] || map[nx][ny] <= water);
							else {
								visited[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
						}
						q.pop();
					}
				}
			}
		}
	}
	return localSafety;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			maxLength = max(maxLength, map[i][j]);
		}
	}

	for (int water = 1; water < maxLength; water++) {
		maxSafety = max(maxSafety, bfs(water));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				visited[i][j] = false; // visted 초기화
	}
	cout << maxSafety << endl;
	return 0;
}