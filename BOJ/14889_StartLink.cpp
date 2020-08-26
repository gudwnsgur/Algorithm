#include <iostream>
#include <algorithm>
using namespace std;

int minDiff = 19000;
int ability[21][21] = { 0, };
int stark[11];
bool team[21] = { false , };
bool visited[21] = { false, };

void checkMin(int n) {
	int teamStark = 0, teamLink = 0;
	for (int i = 1; i <= n-1; i++) {
		for (int j = i+1; j <= n; j++) {
			if (team[i] && team[j]) teamStark += (ability[i][j] + ability[j][i]);
			else if (!team[i] && !team[j]) teamLink += (ability[i][j] + ability[j][i]);
		}
	}
	minDiff = min(minDiff, (teamStark > teamLink ? teamStark - teamLink : teamLink - teamStark));
}

void dfs(int length, int n) {
	if (length == n / 2 && stark[0] == 1) {
		for (int i = 0; i < n / 2; i++) {
			team[stark[i]] = true;
		}
		checkMin(n);
		for (int i = 1; i <= n; i++) team[i] = false;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && stark[length - 1] <= i) {
			visited[i] = true;
			stark[length] = i;
			dfs(length + 1, n);;
			visited[i] = false;
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> ability[i][j];
		}
	}

	dfs(0, n);
	cout << minDiff << endl;
	return 0;
}
