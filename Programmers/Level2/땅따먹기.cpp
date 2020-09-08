#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001][4]{ 0, };

int solution(vector<vector<int>> land)
{
	int n = land.size();
	dp[0][0] = land[0][0];
	dp[0][1] = land[0][1];
	dp[0][2] = land[0][2];
	dp[0][3] = land[0][3];	// 초기화

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][3])) + land[i][0];
		dp[i][1] = max(dp[i - 1][0], max(dp[i - 1][2], dp[i - 1][3])) + land[i][1];
		dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3])) + land[i][2];
		dp[i][3] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + land[i][3];
	} // dp[i]의 해당 열을 제외한 dp[i-1]중 최대 

	return max(dp[n-1][0], max(dp[n-1][1], max(dp[n-1][2], dp[n-1][3])));
}