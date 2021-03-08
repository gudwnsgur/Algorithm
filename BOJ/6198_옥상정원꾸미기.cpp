#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define endl '\n'
using namespace std;

int main() {
	int n;
	long long res = 0;
	cin >> n;
	vector<int> v(n+1);
	for (int i = 1; i <= n; i++) cin >> v[i];

	stack<pair<int, int>> s;
	s.push({ v[n], 0 });
	
	for (int i = n - 1; i >= 1; i--) {
		
		int check = 0;
		while (s.top().first < v[i]) {
			res += s.top().second;
			check += 1 + s.top().second;
			s.pop();
			if (s.empty()) break;
		}
		s.push({ v[i], check });
	}
	while (!s.empty()) {
		res += s.top().second;
		s.pop();
	}
	cout << res << endl;
	return 0;
}

