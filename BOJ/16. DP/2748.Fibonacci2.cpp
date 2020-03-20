#include <iostream>
using namespace std;


int main() {
	int n;
	cin >> n;
	long long fibo[91];
	fibo[0] = 0;	fibo[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}
	cout << fibo[n];
	return 0;
}