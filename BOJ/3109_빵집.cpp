#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int r, c;
int cnt = 0;

string str;
vector<vector<char>> map;
vector<vector<bool>> visited;
bool finished = false;

bool dfs(int x, int y) {
	if (y == c) {
		cnt++;
		visited[x][y] = finished = true;
		return visited[x][y];
	}

	for (int i = -1; i <= 1; i++) {
		if (finished) break;
		int nx = x + i, ny = y + 1;
		if (nx <= 0 || nx > r || ny > c) continue;
		if (map[nx][ny] == '.' && !visited[nx][ny]) visited[x][y] = dfs(nx, ny);
	}
	return visited[x][y] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	map = vector<vector<char>>(r + 1, vector<char>(c + 1));
	visited = vector<vector<bool>>(r + 1, vector<bool>(c + 1, false));

	for (int i = 1; i <= r; i++) {
		cin >> str;
		for (int j = 1; j <= str.size(); j++) {
			map[i][j] = str[j - 1];
		}
	}

	for (int i = 1; i <= r; i++) {
		finished = false;
		visited[i][1] = dfs(i, 1);
	}

	cout << cnt << endl;
	return 0;
}

