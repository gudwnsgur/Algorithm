#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll unsigned long long
using namespace std;


int main() {
	vector<vector<ll>> v;
	v = vector<vector<ll>>(31, vector<ll>(31, 0));

	for (int i = 0; i <= 30; i++) v[0][i] = 1;

	for (int i = 1; i <= 30; i++) {
		for (int j = i; j <= 30; j++) {
			v[i][j] = v[i - 1][j] + v[i][j-1];
		}
	}


	int n;
	cin >> n;
	while (n) {
		cout << v[n][n] << endl;
		cin >> n;
	}

	return 0;
}


