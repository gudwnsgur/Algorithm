#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int dp[501] = { 0, };
int time[501];
vector<int> v[501];

int sol(int p) {
	if (dp[p]) return dp[p];
	int localTime = 0;

	for (int i = 0; i < v[p].size(); i++) {
		localTime = max(localTime, sol(v[p][i]));
	}
	dp[p] = localTime + time[p];
	return dp[p];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i];
		int input;
		while (1) {
			cin >> input;
			if (input == -1) break;
			v[i].push_back(input);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << sol(i) << endl;
	}
	return 0;
}