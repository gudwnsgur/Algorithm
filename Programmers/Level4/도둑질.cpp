#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long first_dp[1000001]{ 0, };
long long last_dp[1000001]{ 0, };
int solution(vector<int> money)
{
	if (money.size() == 1) return money.back();
	if (money.size() == 2) return max(money[0], money[1]);
	// 1 2 3 
	
	// 첫집을 훔치는 경우
	first_dp[0] = money[0];
	first_dp[1] = money[0];

	// 첫집을 훔치지 않는 경우 (마지막 집을 훔칠 수 있음)
	// last_dp[0]=0
	last_dp[1] = money[1];


	for (int i = 2; i < money.size() - 1; i++) {
		first_dp[i] = max(first_dp[i - 2] + money[i], first_dp[i - 1]);
	}
	for (int i = 2; i < money.size(); i++) {
		last_dp[i] = max(last_dp[i - 2]+money[i], last_dp[i-1]);
	}


	return max(first_dp[money.size() - 2], last_dp[money.size() - 1]);
}

// testCase
int main() {
	cout << solution({ 1,2,5,2,3,6,10,2,3 });
	return 0;
}

// 1 2 5 2 3 6 10 2 3

// 1 5 3 10 
// 3 10 3 5 