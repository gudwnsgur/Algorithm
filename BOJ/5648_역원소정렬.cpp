#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#define endl '\n'
#define ll  long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, num;
	priority_queue<ll, vector<ll>, greater<ll>> pq;

	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> num;
		
		string str = to_string(num);
		reverse(str.begin(), str.end());
		pq.push(stoll(str));
	}

	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}

