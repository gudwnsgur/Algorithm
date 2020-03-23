#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dp[101][101]{ 0, };

int solution(int m, int n, vector<vector<int>> puddles)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = -1;
		}
	}
	// 중간 : -1
    
	for (int i = 0; i < puddles.size(); i++) {
		dp[puddles[i][1]-1][puddles[i][0] - 1] = 0;
	} // 웅덩이 : 0

	int x=1, y = 1;
	while (dp[0][x] != 0) {
		dp[0][x] = 1;
		x++;
	}
	while (dp[y][0] != 0) {
		dp[y][0] = 1;
		y++;
	}
	for (; x < m; x++) dp[0][x] = 0;
	for (; y < n; y++) dp[y][0] = 0;
	

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (dp[i][j] == -1) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%1000000007;
			} // 물웅더이가 아니라면 경우의 수 추가
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}

	return dp[n - 1][m - 1];
}


int main() {
	cout << solution(8, 5, { {1,2} ,{3,3} , {2,1}});
	return 0;
}
