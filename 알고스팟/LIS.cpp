#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define inf -1000001
using namespace std;

int main() {
	int tc, n, node;
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<int> lis;
		lis.push_back(inf);
		for (int i = 0; i < n; i++) {
			cin >> node;
			if (lis.back() < node) lis.push_back(node);
			else lis[lower_bound(lis.begin(), lis.end(), node) - lis.begin()] = node;
		}
		cout << lis.size() - 1 << endl;
	}
	return 0;
}