#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
#define ll long long
#define MAX 200000 * 1000000000
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}
ll solve(int n) {
	ll sum = 0, res;
	vector<pair<int, int>> delivery(n);
	vector<int> pickUp(n);
	for (int i = 0; i < n; i++) {
		cin >> delivery[i].first;
		delivery[i].second = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> pickUp[i];
		sum += pickUp[i];
	}
	sort(delivery.begin(), delivery.end(), compare);
	res = min(sum, (ll)delivery[delivery.size()-1].first);

	for (int i = 0; i < delivery.size(); i++) {
		sum -= pickUp[delivery[i].second];
		res = min(res, max(sum, (ll)delivery[i].first));
	}
	return res;
}

int main() {
	int testCase, n;
	cin >> testCase;
	while (testCase--) {
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}
