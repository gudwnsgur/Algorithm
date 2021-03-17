#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, m, cnt = 0;
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
vector<vector<int>> map, dp;


// dp[x][y] : (x, y)에서 (n, m)으로의 경로 개수
int dfs(int x, int y) {
	if (x == n && y == m) return 1; 
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x, ny = dy[i] + y;
		if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
		if (map[x][y] > map[nx][ny]) {
			dp[x][y] += dfs(nx, ny);
		}
	}
	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	map = vector<vector<int>>(n + 1, vector<int>(m + 1));
	dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	
	cout << dfs(1, 1) << endl;

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dp[i][j] << ' ';
		}cout << endl;
	}
	return 0;
}
