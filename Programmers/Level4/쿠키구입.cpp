#include <vector>
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n;
int leftSum = 0, rightSum = 0;
vector<vector<int>> dp[2];

int solution(vector<int> cookie) {
	int answer = 0;
	n = cookie.size();
	dp[0] = vector<vector<int>>(n, vector<int>(n, 0));
	dp[1] = vector<vector<int>>(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		leftSum = 0, rightSum = 0;
		for (int j = i; j < n; j++) {
			leftSum += cookie[j];
			dp[0][i][j] += leftSum;
			
			rightSum += cookie[n - j - 1];
			dp[1][i][j] += rightSum;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n - 1; j++) {
			int cnt = n-j-1;
			for (int k = 0; k < cnt; k++) {
				if (dp[0][i][j] == dp[1][k][cnt-1]) 
					answer = max(answer, dp[0][i][j]);
			}
		}
	}

	return answer;
}
int main() {
	cout << solution({ 1,1,2,3 }) << endl;
	return 0;
}