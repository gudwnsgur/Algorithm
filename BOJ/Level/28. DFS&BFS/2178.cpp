#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool map[100][100];
bool visited[100][100] = { false, };
queue<pair<int, int>> q;

int bfs(int n, int m) {
	q.push(make_pair(0, 0));
	visited[0][0] = true;

	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		for (int i = 0; i < size; i++) {
			int first = q.front().first, second = q.front().second;
			if (first == n-1 && second == m-1) return cnt;

			if (first != 0) if (map[first - 1][second] && !visited[first-1][second]) {
				visited[first - 1][second] = true;
				q.push(make_pair(first - 1, second));
			}
			if (first != n - 1) if (map[first + 1][second] && !visited[first+1][second]) {
				visited[first + 1][second] = true;
				q.push(make_pair(first + 1, second));
			}
			if (second != 0) if (map[first][second - 1] && !visited[first][second-1]) {
				visited[first][second-1] = true;
				q.push(make_pair(first, second - 1));
			}
			if (second != m - 1) if (map[first][second + 1] && !visited[first][second+1]) {
				visited[first][second+1] = true;
				q.push(make_pair(first, second + 1));
			}
			q.pop();
		}
	}
}

int main() {
	int n, m;
	string str;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] == '1' ? true : false;
		}
	}

	cout << bfs(n, m) << endl;
	return 0;
}