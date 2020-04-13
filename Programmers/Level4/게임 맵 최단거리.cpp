#include<vector>
#include <queue>
#include <iostream>
using namespace std;

bool visited[101][101]{ false, };
bool map[101][101]{ false , };
int solution(vector<vector<int> > maps)
{
	int answer = 0;

	int n = maps.size();
	int m = maps[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = maps[i][j];
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;

	while (!q.empty()) {
		answer++;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			if (x == n-1 && y == m-1) return answer;

			if (x != 0 && !visited[x - 1][y] && map[x -1][y]) {
				visited[x - 1][y] = true;
				q.push(make_pair(x-1, y));
			}
			if (x != n && !visited[x + 1][y] && map[x +1][y]) {
				visited[x + 1][y] = true;
				q.push(make_pair(x + 1, y));
			}
			if (y != 0 && !visited[x][y-1] && map[x][y-1]) {
				visited[x][y-1] = true;
				q.push(make_pair(x, y-1));
			}
			if (y != m && !visited[x][y+1] && map[x][y+1]) {
				visited[x][y+1] = true;
				q.push(make_pair(x, y+1));
			}
			q.pop();
		}
		

	}
	return -1;

}

int main() {
	int n = solution({ {1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1} });
	return 0;
}