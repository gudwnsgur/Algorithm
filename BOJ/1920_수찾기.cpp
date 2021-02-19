#include <iostream>
#include <vector>
#include <map>
#include <set>
#define ll long long
#define endl '\n'
using namespace std;

set<ll> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		s.insert(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << (s.find(num) == s.end() ? 0 : 1) << endl;
	}

	return 0;
}
