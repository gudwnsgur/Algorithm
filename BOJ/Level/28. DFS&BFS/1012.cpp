#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool map[51][51]{ false, };
bool visited[51][51]{ false , };
int result = 0;


void dfs(int i, int j, int n, int m) {
	visited[i][j] = true;	// map[i][j] 방문

	if (i != 0 && !visited[i - 1][j] && map[i - 1][j])	dfs(i - 1, j, n, m);
	if (j != 0 && !visited[i][j - 1] && map[i][j - 1]) dfs(i, j - 1, n, m);
	if (i != n - 1 && !visited[i + 1][j] && map[i + 1][j]) dfs(i + 1, j, n, m);
	if (j != m - 1 && !visited[i][j + 1] && map[i][j + 1]) dfs(i, j + 1, n, m);
}

int main() {
	int testCase, M, N;
	int v;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		cin >> M >> N >> v; // 가로, 세로, 배추 개수

		result = 0; // 결과 초기화

		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				map[j][k] = false;	// map 초기화
				visited[j][k] = false; // visited 초기화
			}
		}

		for (int j = 0; j < v; j++) {
			int a, b;
			cin >> a >> b;
			map[a][b] = true;
		}

		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (!visited[j][k] && map[j][k]) {
					result++;
					dfs(j, k, M, N);
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}