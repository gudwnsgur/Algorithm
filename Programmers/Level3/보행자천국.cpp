#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;
	int MOD = 20170805;
	int dp[501][501] = { 0, };

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = 0;
		}
	}
	dp[1][1] = 1;
	for (int i = 1; i < n; i++) {
		if (city_map[0][i] == 1) dp[1][i + 1] = 0;
		else dp[1][i + 1] = 1;
	}
	for (int i = 1; i < m; i++) {
		if (city_map[i][0] == 1) dp[i + 1][1] = 0;
		else dp[i + 1][1] = 1;
	}


	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (city_map[i][j] != 1) {
				int left = 0, up = 0;
				if (city_map[i - 1][j] == 2) {
					int index = i - 1;
					while (index >= 0 && city_map[index][j] == 2) index--;
					up = (dp[index + 1][j+1] % MOD);
				} 
				else up = (dp[i][j + 1] % MOD);

				if (city_map[i][j - 1] == 2) {
					int index = j - 1;
					while (index >= 0 && city_map[i][index] == 2 )index--;
					left = (dp[i + 1][index+1] % MOD);
				}
				else left = (dp[i + 1][j]%MOD);

				dp[i + 1][j + 1] = (up%MOD + left%MOD)%MOD;
			}
		}
	}
	return dp[m][n]%MOD;
}

int main() {
	cout << solution(7, 8, { {0,0,2,0,2,0,0,2},{ 0,0,2,0,0,1,2,0 },{ 0,0,2,2,0,0,0,2 },{ 0,0,2,0,0,0,2,0 },
	{ 0,0,2,0,0, 1,0,0 },{ 0,0,0,2,2,0,0,0 },{ 2,2,0,0,1,0,0,0 } });
	return 0;
}