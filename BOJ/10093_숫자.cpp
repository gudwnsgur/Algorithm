#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define ll unsigned long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll a, b;
	cin >> a >> b;
	if (a > b) swap(a, b);

	if (a == b) cout << 0 << endl;
	else {
		cout << b - a - 1 << endl;
		for (ll i = a + 1; i < b - 1; i++) cout << i << ' ';
		if (b - a - 1 != 0) cout << b - 1 << endl;
	}
	return 0;
}
