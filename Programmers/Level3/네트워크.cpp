#include <string>
#include <vector>
using namespace std;

bool visited[201] = { false, };
int cnt = 0;

void dfs(int node, vector<vector<int>> computers) {
	for (int i = 0; i < computers[node].size(); i++) {
		if (i != node && computers[node][i] && !visited[i]) {
			visited[i] = true;
			dfs(i, computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {

	for (int i = 0; i < computers.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			cnt++;
			dfs(i, computers);
		}
	}

	return cnt;
}