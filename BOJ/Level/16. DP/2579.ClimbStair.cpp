#include <iostream>
#include <algorithm>
using namespace std;

int dp[301]{ 0, };	// 계단 최대 수

int main() {
	int n;
	cin >> n;
	int* stair = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> stair[i];
	}

	dp[0] = stair[0];
	dp[1] = (stair[0] + stair[1]);
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);


	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + stair[i], stair[i - 1] + stair[i] + dp[i - 3]);
	}
	// 계단 X 를 밟을 두가지 경우
	/*
		1. X-3 을 밟고 X-1, X를 밟는 경우
		2. X-2 를 밟고 X를 밟는 경우
	*/
	cout << dp[n - 1];

	return 0;
}



