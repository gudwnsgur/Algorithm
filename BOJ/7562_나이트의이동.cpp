#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define X first
#define Y second
#define endl '\n'
using namespace std;


int l;
pair<int, int> src, dest;
vector<vector<bool>> visited;
int dx[8] = {-2, -1, 1, 2, 2 ,1, -1, -2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };


int bfs() {
	int result = 0;
	queue<pair <int ,pair<int, int>>> q;
	q.push({ 0, src });

	while (!q.empty()) {
		int curTime = q.front().X;
		pair<int, int> cur = q.front().Y;
		if (cur.X == dest.X && cur.Y == dest.Y) return curTime;

		for (int i = 0; i < 8; i++) {

			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= l || ny < 0 || ny >= l) ;
			else if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ curTime + 1, { nx, ny } });
			}
		}
		q.pop();
	}

	return result;
}

int main () {
	int testCase;
	cin >> testCase;

	while (testCase--) {
		cin >> l;
		visited = vector<vector<bool>>(l, vector<bool>(l, false));
		cin >> src.X >> src.Y >> dest.X >> dest.Y;

		visited[src.X][src.Y] = true;

		cout << bfs() << endl;
	}
	return 0;
}
