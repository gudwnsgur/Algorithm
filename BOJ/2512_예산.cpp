#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#define ll long long
using namespace std;

ll n, total;
vector<ll> budget;

void input() {
	cin >> n;
	budget = vector<ll>(n);
	for (ll i = 0; i < budget.size(); i++) cin >> budget[i];
	cin >> total;
}

ll sumBudget(ll curLimit) {
	ll res = 0;
	for (int i = 0; i < budget.size(); i++) {
		res += (curLimit > budget[i] ? budget[i] : curLimit);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	ll left = 0;
	ll right = *max_element(budget.begin(), budget.end());
	ll upperLimit = 0;

	while (left <= right) {
		ll mid = (left + right) / 2;
		if (sumBudget(mid) > total) right = mid - 1;
		else {
			upperLimit = mid;
			left = mid + 1;
		}
	}
	cout << upperLimit << endl;
	return 0;
}

