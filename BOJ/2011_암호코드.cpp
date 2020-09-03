#include <iostream>
#include <string>
#include <algorithm>
#define MOD 1000000
using namespace std;

int n;
int dp[5001] = { 1, };

bool solution(string str) {
	if (str[0] == '0') return false;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == '0' && (str[i - 1] > '2' || str[i-1]=='0')) return false;
		dp[i] = (dp[i] + dp[i - 1]) % MOD;	// 묶지 않을 경우

		if (str[i - 1] == '1' || (str[i - 1] == '2' && str[i] < '7')){
			if (str[i] != '0') {
				if (i == 1) dp[i] += 1;
				else dp[i] = (dp[i] + dp[i - 2]) % MOD;
			}
			else {
				if (i == 1) dp[i] = 1;
				else dp[i] = dp[i - 2];
			}
		} // 묶을 경우
	}
	return true;
}

int main() {
	string str;
	cin >> str;
	cout << (solution(str) ? dp[str.size() - 1]%MOD : 0) << endl;
	return 0;
}