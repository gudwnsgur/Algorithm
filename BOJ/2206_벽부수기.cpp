#include <iostream>
#include <queue>
#include <string>
using namespace std;

bool map[1000][1000];
bool visited[1000][1000][2] = { false, };
queue<pair<int, int>> q;

int bfs(int n, int m) {
	q.push(make_pair(0, 0));
	visited[0][0][0] = true;

	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		for (int i = 0; i < size; i++) {
			int first = q.front().first, second = q.front().second;
			if (first == n - 1 && second == m - 1) return cnt;

			if (first != 0 ) { // move left
				if (map[first - 1][second] && !visited[first][second][0]) {
					// 벽X +  부수지 않은 상태로 들린적이 없는가
					visited[first - 1][second][0] = true;
					q.push(make_pair(first - 1, second));
				}
				else if (!map[first - 1][second] && !visited[first][second][1]) {
					// 벽O + 현재 벽을 부수지 않은 상태
					visited[first - 1][second][1] = true;
					q.push(make_pair(first - 1, second));
				}
			}
			if (first != n - 1 && !visited[first + 1][second]) { // move right
				if (map[first + 1][second]) {
					visited[first + 1][second] = true;
					q.push(make_pair(first + 1, second));
				}
				else if (!map[first + 1][second] ) {
					visited[first + 1][second] = true;
					q.push(make_pair(first + 1, second));
				}
			}
			if (second != 0 && !visited[first][second - 1]) { // move up
				if (map[first][second - 1]) {
					visited[first][second - 1] = true;
					q.push(make_pair(first, second - 1));
				}
				else if (!map[first][second - 1] ) {
					visited[first][second - 1] = true;
					q.push(make_pair(first, second - 1));
					broken.push(true);
				}
			}
			if (second != m - 1 && !visited[first][second + 1]) { // move down
				if (map[first][second + 1]) {
					visited[first][second + 1] = true;
					q.push(make_pair(first, second + 1));
				}
				else if (!map[first][second + 1] ) {
					visited[first][second + 1] = true;
					q.push(make_pair(first, second + 1));
				}
			}
			q.pop();
		}
	}
	return -1;
}

int main() {
	int n, m;
	string str;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] == '0' ? true : false;
		}
	}

	cout << bfs(n, m) << endl;
	return 0;
}