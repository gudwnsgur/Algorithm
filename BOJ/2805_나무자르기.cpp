#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <numeric>
#define ll long long
using namespace std;


vector<int> height;

ll cutting(ll cur) {
	ll res = 0;
	for (int i = 0; i < height.size(); i++) {
		if (cur < height[i]) res += (ll)(height[i] - cur);
	}

	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n, m;
	cin >> n >> m;
	height = vector<int>(n);
	for (int i = 0; i < n; i++) cin >> height[i];

	// m만큼 가져가기 위해 도려내는 높이
	// 0 => 20 + 15 + 10 + 17,  20 => 0 + 0 + 0 + 0 

	ll right = *max_element(height.begin(), height.end());
	ll left = 0;
	ll res = 0;

	while (left <= right) {
		ll mid = (right + left) / 2;
		ll cut = cutting(mid);
		
		if (cut == m) {
			cout << mid << endl;
			return 0;
		}

		if (cut > m) {
			res = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << res << endl;
	return 0;
}
