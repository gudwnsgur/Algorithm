#include <iostream>
#include <queue>
#define endl '\n'
#define MAX 1001
#define X first
#define Y second
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1 , -1, 0, 0 };
char map[MAX][MAX];
queue<pair<int, int>> J;
queue<pair<int, int>> F;
bool jVisited[MAX][MAX] = { false, };
bool fVisited[MAX][MAX] = { false, };
int n, m;

int bfs() {
	int length = 0;
	while (!J.empty()) {
		/*		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << ' ';
			}cout << endl;
		}
		*/

		length++;
		int jSize = J.size(), fSize = F.size();
		for (int i = 0; i < jSize; i++) {
			if (J.front().X == 0 || J.front().X == n - 1 || J.front().Y == 0 || J.front().Y == m - 1) {
				if(map[J.front().X][J.front().Y] != 'F') return length;
			}
			for (int j = 0; j < 4; j++) {
				int nx = J.front().X + dx[j];
				int ny = J.front().Y + dy[j];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m);
				else if (!jVisited[nx][ny] && map[nx][ny] == '.') {
					J.push(make_pair(nx, ny));
					jVisited[nx][ny] = true;
				}
			}
			J.pop();
		}

		for (int i = 0; i < fSize; i++) {
			for (int j = 0; j < 4; j++) {
				int nx = F.front().X + dx[j];
				int ny = F.front().Y + dy[j];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m);
				else if (!fVisited[nx][ny] && map[nx][ny] == '.') {
					F.push(make_pair(nx, ny));
					fVisited[nx][ny] = true;
					map[nx][ny] = 'F';
				}
			}
			F.pop();
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				J.push(make_pair(i, j));
				map[i][j] = '.';
				jVisited[i][j] = true;
			}
			if (map[i][j] == 'F') {
				F.push(make_pair(i, j));
				fVisited[i][j] = true;
			}
		}
	}
	int result = bfs();
	if (result == -1) cout << "IMPOSSIBLE" << endl;
	else cout << result << endl;
	return 0;
}