#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int n;
		cin >> n;
		string a, b = "1";
		vector<char> c(n, 0);
		cin >> a;

		c[0] = '1' + a[0];
		for (int j = 1; j < n; j++) {
			if (c[j - 1] != a[j] + '1') {
				b.push_back('1');
			}
			else {
				b.push_back('0');
			}
			c[j] = a[j] + b[j];
		}
		cout << b << endl;
	}

	return 0;
}

