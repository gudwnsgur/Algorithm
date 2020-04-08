#include <iostream>
#include <queue>
#include <string>
#define MAX 101

using namespace std;

bool map[MAX][MAX]{ false, };
bool visited[MAX][MAX]{ false, };
queue<pair<int, int>> curQ; // 현재 좌표
queue<pair<int, int>> nextQ; // 다음으로 가야 할 좌표
int result = 1;

void bfs(int n, int m) {
	while (!curQ.empty()) 
	{
		while (!curQ.empty()) 
		{
			if (curQ.front().first == n && curQ.front().second == m) return;
			// 현재 좌표가 도착지점이면 return
			nextQ.push(curQ.front());
			curQ.pop();
		} //현재 모든 좌표를 nextQ로 이동

		while (!nextQ.empty()) {
			int i = nextQ.front().first; // 확인할 x 좌표 : i
			int j = nextQ.front().second; // 확인할 y 좌표 : j

			// nextQ에 담긴 모든 현재 좌표의 다음 좌표를 curQ로 이동

			if (map[i+1][j] && !visited[i+1][j] && i != n) {
				curQ.push(make_pair(i + 1, j));
				visited[i + 1][j] = true;
			} // 아래로 이동 
			if (map[i][j+1] && !visited[i][j+1] && j != m) {
				curQ.push(make_pair(i, j+1));
				visited[i][j+1] = true;
			} // 우로 이동
			if (i != 0 && map[i-1][j] && !visited[i-1][j] ) {
				curQ.push(make_pair(i - 1, j));
				visited[i - 1][j] = true;
			} // 위로 이동
			if (j != 0 && map[i][j-1] && !visited[i][j-1]) {
				curQ.push(make_pair(i, j-1));
				visited[i][j-1] = true;
			} // 좌로 이동

			nextQ.pop();
		}
		result++;
		// 한 칸을 이동했다는 의미
	}
}


int main() {
	int n, m;
	cin >> n >> m;
	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			if (line[j] == '1') map[i][j] = true;
		}
	} // map 초기화
    
	curQ.push(make_pair(0, 0));
	visited[0][0] = true;
	bfs(n-1, m-1);
	cout << result;
	return 0;
}