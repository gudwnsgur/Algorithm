#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dp[100001]{ 0, };

int solution(int n, vector<int> money) 
{
	int answer = 0;	
	dp[0] = 1;

	for (int i = 0; i < money.size(); i++) {
		for (int j = 1; j <= n; j++) {
			if (money[i] <= j) {
				dp[j] += dp[j-money[i]];
			}
		}
	}
	return dp[n];
}
int main() {
	cout << solution(10, { 1,2,5 });
	return 0;
}