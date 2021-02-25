#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

vector<vector<ll>> v;
int main() {
	v = vector<vector<ll>>(65, vector<ll>(10, 1));

	for (int i = 1; i < 65; i++) {
		for (int j = 8; j >= 0; j--) {
			v[i][j] = v[i][j + 1] + v[i - 1][j];
		}
	}

	int testCase, n;
	cin >> testCase;
	while (testCase--) {
		cin >> n;
		cout << v[n][0] << endl;
	}
	return 0;
}

