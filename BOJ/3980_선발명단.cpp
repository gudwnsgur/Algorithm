#include <iostream>
#include <algorithm>
using namespace std;

int arr[11][11];
int maxStat = 0;
bool visited[11] = { false, };
int combination[11];

void dfs(int length) {
	if (length == 11) {
		int sum = 0;
		for (int i = 0; i < 11; i++) {
			sum += arr[i][combination[i]];
		}
		maxStat = max(maxStat, sum);
		return;
	}
	for (int i = 0; i < 11; i++) {
		if (!visited[i] && arr[length][i]) {
			visited[i] = true;
			combination[length] = i;
			dfs(length + 1);
			visited[i] = false;
		}
	}
}
int main() {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		
		for (int j = 0; j < 11; j++) {
			for (int k = 0; k < 11; k++) {
				cin >> arr[j][k];
			}
		}

		int max = 0;
		
		dfs(0);

		cout << maxStat << endl;
		maxStat = 0;
	}
	return 0;
}