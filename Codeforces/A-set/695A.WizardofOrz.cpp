#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n;
		cin >> n;
		string str1 = "989", str2 = "0123456789";
		if (n <= 3) cout << str1.substr(0, n) << endl;
		else {
			n -= 3;
			for (int i = 0; i < n/10; i ++) {
				str1 += str2;
			}
			str1 += str2.substr(0, n % 10);
			cout << str1 << endl;
		}
	}
	return 0;
}
	
