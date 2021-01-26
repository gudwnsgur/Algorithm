#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
#define ll long long
using namespace std;


int solution() {
	ll n;
	ll res = 0;
	cin >> n;
	if (n == 1 || n == 2) return 0;
	vector<ll> v(n);
	string str = "";
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (ll i = 1; i < n - 1; i++) {
		if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
			str.push_back('U');
			res++;
		}
		else if (v[i - 1] > v[i] && v[i] < v[i + 1]) {
			str.push_back('D');
			res++;
		}
		else str.push_back('N');
	}
	if (str.find("UDU") != string::npos || str.find("DUD") != string::npos) {
		return res - 3;
	}
	else if (str.find("DU") != string::npos || str.find("UD") != string::npos) {
		return res - 2;
	}
	else if (str.find("D") != string::npos || str.find("U") != string::npos) {
		return res - 1;
	}
	return res;
}
int main() {
	ll testCase;
	cin >> testCase;
	while (testCase--) {
		cout << solution() << endl;
	}
	return 0;
}


