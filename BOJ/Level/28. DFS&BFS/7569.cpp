// 메모리 초과

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101

int ***tomato;
int day = -1;
queue<pair<pair<int, int>, int>> curQ;
queue<pair<pair<int, int>, int>> nextQ;


void bfs(int n, int m, int h)
{
	while (!curQ.empty())
	{
		day++;
		//cout << day << " 일 차 " << endl;
		while (!curQ.empty()) {
			nextQ.push(curQ.front());
			// cout << "검사 할 노드 : " << curQ.front().first << ' ' << curQ.front().second << endl;
			curQ.pop();
		}
		while (!nextQ.empty()) {
			int i = nextQ.front().first.first;
			int j = nextQ.front().first.second;
			int k = nextQ.front().second;

			if (i != n && tomato[k][i + 1][j] == 0) {
				tomato[k][i + 1][j] = 1;
				curQ.push(make_pair(make_pair(i + 1, j), k));
			}
			if (i != 0 && tomato[k][i - 1][j] == 0) {
				tomato[k][i - 1][j] = 1;
				curQ.push(make_pair(make_pair(i - 1, j), k));
			}
			// 상하 (i)

			if (j != m && tomato[k][i][j + 1] == 0) {
				tomato[k][i][j + 1] = 1;
				curQ.push(make_pair(make_pair(i, j + 1), k));

			}
			if (j != 0 && tomato[k][i][j - 1] == 0) {
				tomato[k][i][j - 1] = 1;
				curQ.push(make_pair(make_pair(i, j - 1), k));
			}
			// 좌우 (j)

			if (k != h && tomato[i][j][k + 1] == 0) {
				tomato[k + 1][i][j] = 1;
				curQ.push(make_pair(make_pair(i, j), k + 1));
			}
			if (k != 0 && tomato[i][j][k - 1] == 0) {
				tomato[k - 1][i][j] = 1;
				curQ.push(make_pair(make_pair(i, j), k - 1));
			}
			// 위아래 (k)
			nextQ.pop();
		}
	}
	for (int k = 0; k <= h; k++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (tomato[k][i][j] == 0) {
					day = -1;
					return;
				}
			}
		}
	}
}

int main() {
	int n, m, h;

	cin >> m >> n >> h;

	tomato = new int** [h];
	for (int i = 0; i < n; i++) {
		tomato[i] = new int* [n];
		for (int j = 0; j < m; j++) {
			tomato[i][j] = new int[m];
		}
	}

	for (int k = 0; k < h; k++) { // 2
		for (int i = 0; i < n; i++) { // 3
			for (int j = 0; j < m; j++) { // 5
				cin >> tomato[k][i][j];
				if (tomato[k][i][j] == 1) {
					curQ.push(make_pair(make_pair(i, j), k));
				}
			}
		}
	}

	bfs(n - 1, m - 1, h - 1);
	cout << day;
	return 0;
}