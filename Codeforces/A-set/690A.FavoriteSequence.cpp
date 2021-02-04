#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;


void solve(int n) {
	vector<int> v(n, 0);
	int num;
	for (int i = 0; i < n; i++) cin >> v[i];
	
	for (int i = 0, j=n-1; i < n/2; i ++, j--) {
		cout << v[i] << ' ' << v[j] << ' ';
	}
	n%2 ? cout << v[n/2] <<endl : cout << endl;

	return;
}

int main() {
	int testCase, n;
	cin >> testCase;
	while (testCase--) {
		cin >> n;
		solve(n);
	}
	return 0;
}
