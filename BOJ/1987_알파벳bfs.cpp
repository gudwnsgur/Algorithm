#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<char>> map;
bool visited[26] = { false, };
int result = 1;
int r, c;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int length, int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x, ny = dy[i] + y;
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (!visited[map[nx][ny] - 'A']) {
			visited[map[nx][ny] - 'A'] = true;
			result = max(length + 1, result);
			dfs(length + 1, nx, ny);
			visited[map[nx][ny] - 'A'] = false;
		}
	}
}

int main () {
	cin >> r >> c;
	
	map = vector<vector<char>>(r, vector<char>(c));

	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			map[i][j] = str[j];
		}
	}
	visited[map[0][0] - 'A'] = true;

	dfs(1, 0, 0);
	cout << result << endl;
	return 0;
}
