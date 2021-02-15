#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int solve(int n, int a, int b) {
	for (int i = 2, res = 1; ; i *= 2, res++) {
		if (a / i == b / i) return res;
	}
}


int main() {
	int n, a, b;
	cin >> n >> a >> b;
	if (a > b) swap(a, b);

	cout << solve(n, a-1, b-1) << endl;
	return 0;
}
