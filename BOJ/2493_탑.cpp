#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define endl '\n'
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n), res(n);
	stack<pair<int ,int>> s;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	res[0] = 0;
	s.push({ 1, v[0] });

	for (int i = 1; i < n; i++) {
		while (s.top().second <= v[i]) {
			s.pop();
			if (s.empty()) break;
		}
		res[i] = (s.size() == 0 ? 0 : s.top().first);
		s.push({ i + 1, v[i] });
	}
	for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
	cout << endl;
	return 0;
}

