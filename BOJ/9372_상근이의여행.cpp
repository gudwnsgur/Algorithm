#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	int tc, n, m, a, b;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
		}
		cout << n - 1 << endl;
	}


	return 0;
}


