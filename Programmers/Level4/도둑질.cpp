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
	first_dp[0] = money[0];
	first_dp[1] = money[1];
	first_dp[2] = money[0] + money[2];


	last_dp[1] = money[1];
	last_dp[2] = max(money[1], money[2]);


	for (int i = 3; i < money.size() - 1; i++) {
		first_dp[i] = max(first_dp[i - 3], first_dp[i - 2]) + money[i];
	}
	for (int i = 3; i < money.size(); i++) {

		last_dp[i] = max(last_dp[i - 3], last_dp[i - 2]) + money[i];
	}


	return max(first_dp[money.size() - 2], last_dp[money.size() - 1]);
}
int main() {
	cout << solution({ 1,2,5,2,3,6,10,2,3 });
	return 0;
}

// 1 2 5 2 3 6 10 2 3

// 1 5 3 10 
// 3 10 3 5 