#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll x, y;
	cin >> x >> y;
	ll z = (y * 100)/x;
	if (z == 99 || z == 100) {
		cout << -1 << endl;
		return 0;
	}

	ll left = 1, right = x;
	ll curRate = 0, result = 0;

	while (left <= right) {
		ll mid = (left + right) / 2;
		curRate = ((y + mid) * 100) / (x + mid);

		if (curRate < z+1) left = mid + 1;
		else {
			result = mid;
			right = mid - 1;
		}
	}
	cout << result << endl;
	return 0;
}

