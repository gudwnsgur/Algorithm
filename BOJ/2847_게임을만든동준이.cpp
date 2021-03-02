#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	int n, cnt =0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	

	for (int i = n - 2; i >= 0; i--) {
		if (v[i + 1] <= v[i]) {
			cnt += v[i] - v[i+1] + 1;
			v[i] = v[i + 1] - 1;
		}
	}
	cout << cnt << endl;
	return 0;
}
