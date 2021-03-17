#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <numeric>
using namespace std;
#define ll long long
vector<ll> line;

ll counting(ll length) {
	ll res = 0;
	for (int i = 0; i < line.size(); i++) {
		res += line[i] / length;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, n;
	cin >> k >> n;
	line = vector<ll>(k);
	ll sum = 0;

	for (int i = 0; i < k; i++) {
		cin >> line[i];
		sum += line[i];
	}

	ll left = 1;
	ll right = *max_element(line.begin(), line.end());
	ll res = 0;

	while (left <= right) {
		ll mid = (left + right) / 2;
		int cur = counting(mid);

		if (cur >= n) {
			res = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << res << endl;
	return 0;
}
