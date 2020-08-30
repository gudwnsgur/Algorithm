#include <iostream>
#include <queue>
#define endl '\n'
#define X first
#define Y second
using namespace std;

bool paper[500][500] = { false , };
bool visited[500][500] = { false, };
int dx[4] = { 0, 0, 1, -1 }; // L R U D
int dy[4] = { -1, 1, 0, 0 }; // L R U D

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	vector<pair<int, int>> colored;

	int n, m, num, cnt = 0, maxArea = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
			colored.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < colored.size(); i++) {
		if (!visited[colored[i].X][colored[i].Y] && paper[colored[i].X][colored[i].Y]) {
			//cout << "중점" << colored[i].X << ", " << colored[i].Y << endl;
			int localArea = 0;
			cnt++;
			queue<pair<int, int>> q;
			q.push(colored[i]);
			visited[colored[i].X][colored[i].Y] = true;
			while (!q.empty()) {
				//cout << q.front().X << ' ' << q.front().Y << endl;
				int size = q.size();
				localArea += size;
				for (int k = 0; k < size; k++) {
					for (int j = 0; j < 4; j++) {
						int nx = q.front().X + dx[j];
						int ny = q.front().Y + dy[j];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m);
						else if (visited[nx][ny] || paper[nx][ny] != 1);
						else {
							visited[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
					}
					q.pop();
				}
			}
			maxArea = max(maxArea, localArea);
		}
	}
	cout << cnt << endl << maxArea << endl;
	return 0;
}