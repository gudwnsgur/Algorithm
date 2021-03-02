#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#define endl '\n'
#define ll long long
using namespace std;

int main() {
	int n, num;
	ll res = 0;
	cin >> n;
	vector<ll> minus, plus;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 1) res++;
		else {
			if (num <= 0) minus.push_back(num);
			else plus.push_back(num);
		}
	}

	if (minus.size() != 0) {
		sort(minus.begin(), minus.end());
		for (int i = 0; i < minus.size() - 1; i += 2) {
			res += minus[i] * minus[i + 1];
		}
		if (minus.size() % 2) res += minus[minus.size() - 1];

	}
	if (plus.size() != 0) {
		sort(plus.begin(), plus.end(), greater<ll>());

		for (int i = 0; i < plus.size() - 1; i += 2) {
			res += plus[i] * plus[i + 1];
		}
		if (plus.size() % 2) res += plus[plus.size() - 1];

	}

	cout << res << endl;
	return 0;
}


