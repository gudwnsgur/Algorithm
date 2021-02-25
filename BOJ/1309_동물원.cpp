#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MOD 9901
using namespace std;


int main() {
	int n;
	cin >> n;
	
	vector<int> zoo[3];
	for (int i = 0; i < 3; i++) zoo[i] = vector<int>(n + 1, 1);


	for (int i = 1; i <= n; i++) {
		zoo[0][i] = ( (zoo[0][i - 1] + zoo[1][i - 1])%MOD + zoo[2][i - 1])%MOD;
		zoo[1][i] = (zoo[0][i - 1] + zoo[2][i - 1]) % MOD;
		zoo[2][i] = (zoo[0][i - 1] + zoo[1][i - 1]) % MOD;
	}

	cout << zoo[0][n] % MOD << endl;
}


