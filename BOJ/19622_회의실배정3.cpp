#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define X first
#define Y second
using namespace std;

int n;
vector<pair< pair<int, int>, int>> v;
int dp[100001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e, p;
		cin >> s >> e >> p;
		v.push_back(make_pair(make_pair(s, e), p));
	}
	sort(v.begin(), v.end());
	
	dp[1] = v[0].Y;
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 2] + v[i - 1].Y, dp[i - 1]);
	}
	cout << dp[n] << endl;
	return 0;
}