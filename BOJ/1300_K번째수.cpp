#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#define ll long long
using namespace std;

ll n, k;

ll getOrder(ll cur) {
	ll order = 0;
	for (ll i = 1; i <= n; i++) {
		order += min(n, cur / i);
	}
	return order;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	ll left = 1, right = n*n;
	ll result = 1;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (getOrder(mid) < k) left = mid + 1;
		else {
			result = mid;
			right = mid - 1;
		}
	}
	cout << result << endl;
	return 0;
}

