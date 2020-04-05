#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	long long fibo[1000001]{0,};
	fibo[1] = 1; fibo[2]=2;
	for (int i = 3; i <= n; i++) {
		fibo[i] = (fibo[i - 2] + fibo[i - 1])%15746;
	}
	cout << fibo[n];
	return 0;
}
