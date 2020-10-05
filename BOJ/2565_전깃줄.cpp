#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
vector<pair<int,int>> v;
vector<int> dp;
int n;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	cin >> n;
	v = vector<pair<int, int>>(n+1);
	dp = vector<int>(n+1);
	for (int i = 1; i <= n; i++) 
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), compare);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				if (dp[j] >= dp[i]) dp[i] = dp[j] + 1;
			}
		}
	}
	for (int i = 0; i <= n; i++) cout << dp[i] << ' ';
	cout << n - *max_element(dp.begin(), dp.end()) << endl;
	return 0;
}