#include <iostream>
using namespace std;

int GCD(int a, int b) {
	while (b != 0) {
		int n = a%b;
		a = b;
		b = n;
	}
	return a;
}

int main() {
	int testCase;
	cin >> testCase;
	int a, b;

	for (int i = 0; i < testCase; i++) {
		cin >> a >> b;
		cout << a*b/GCD(a, b) << endl;
	}
	return 0;
}