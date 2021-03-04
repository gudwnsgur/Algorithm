#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#define ll long long
#define endl '\n'
using namespace std;

int main() {
	int n, cnt;
	ll num, res = 0;
	cin >> n >> cnt;
	priority_queue<ll, vector<ll>, greater<ll>> pq;

	for (int i = 0; i < n; i++) {
		cin >> num;
		pq.push(num);
	}

	while (cnt--) {
		ll x = pq.top();
		pq.pop();
		ll y = pq.top();
		pq.pop();

		pq.push(x + y);
		pq.push(x + y);
	}
	while (!pq.empty()) {
		res += pq.top();
		pq.pop();
	}
	cout << res << endl;
	return 0;
}


