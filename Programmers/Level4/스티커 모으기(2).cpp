#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int first_dp[100001]{ 0, };	// 첫 번째 원소를 뜯을 때
int last_dp[100001]{ 0, }; // 첫 번째 원소를 뜯지 않을 때

int solution(vector<int> sticker)
{
    if(sticker.size()==1) return sticker[0];
	first_dp[0] = sticker[0];
	first_dp[1] = sticker[0];

	last_dp[0] = 0;
	last_dp[1] = sticker[1];

	for (int i = 2; i < sticker.size()-1; i++) {
		first_dp[i] = max(first_dp[i - 2] + sticker[i], first_dp[i - 1]);
	}
	for (int i = 2; i < sticker.size(); i++) {
		last_dp[i] = max(last_dp[i - 2] + sticker[i], last_dp[i - 1]);
	}

	return max(first_dp[sticker.size()-2],last_dp[sticker.size() - 1]);
}