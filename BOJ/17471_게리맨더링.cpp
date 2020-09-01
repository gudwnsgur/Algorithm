#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

int n, cnt = 0;
int population[11] = { 1, };
bool graph[11][11] = { false, };
bool group[11] = { false, };
int minDiff = 1000;

bool isCorrected() {
	bool visited[11] = { false, };
	int firstA = 0, firstB = 0;

	// check group A
	for (int i = 1; i <= n; i++) {
		if (group[i]) {
			firstA = i;
			visited[i] = true;
			break;
		}
	}
	if (!firstA) return false;

	queue<int> a;
	a.push(firstA);
	while (!a.empty()) {
		int size = a.size();
		for (int i = 0; i < size; i++) {
			int v = a.front();
			for (int j = 1; j <= n; j++) {
				if (!visited[j]) {
					if (group[j] && graph[v][j]) {
						visited[j] = true;
						a.push(j);
					}
				}
			}
			a.pop();
		}
	}
	for (int i = 1; i <= n; i++) if (group[i] && !visited[i]) return false;


	// initalize visited[]
	for (int i = 0; i < 10; i++) visited[i] = false;

	// check group B 
	for (int i = 1; i <= n; i++) {
		if (!group[i]) {
			firstB = i;
			visited[i] = true;
			break;
		}
	}
	if (!firstB) return false;

	queue<int> b;
	b.push(firstB);
	while (!b.empty()) {
		int size = b.size();
		for (int i = 0; i < size; i++) {
			int v = b.front();
			for (int j = 1; j <= n; j++) {
				if (!visited[j]) {
					if (!group[j] && graph[v][j]) {
						visited[j] = true;
						b.push(j);
					}
				}
			}
			b.pop();
		}
	}
	for (int i = 1; i <= n; i++) if (!group[i] && !visited[i]) return false;

	return true;
}
int checkDiff() {
	int groupA = 0, groupB = 0;
	for (int i = 1; i <= n; i++) {
		if (group[i]) groupA += population[i];
		else groupB += population[i];
	}

	return (groupA > groupB ? groupA - groupB : groupB - groupA);
}

void dfs(int length) {
	if (length == n + 1) { // 그룹이 나뉨
		if (isCorrected()) {	// 그 그룹이 각자 인접해있다면
			minDiff = min(minDiff, checkDiff()); // 차이 계산
		}
		return;
	}
	group[length] = false;
	dfs(length + 1);
	group[length] = true;
	dfs(length + 1);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> population[i];
	for (int i = 1; i <= n; i++) {
		int e;
		cin >> e;
		for (int j = 0; j < e; j++) {
			int s;
			cin >> s;
			graph[i][s] = true;
			graph[s][i] = true;
		}
	}


	dfs(1);
	cout << (minDiff != 1000 ? minDiff : -1) << endl;
	return 0;
}