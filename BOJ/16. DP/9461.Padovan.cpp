#include <iostream>
using namespace std;

int main() {
	long long padovan[101]{ 0,1,1,1,2,2,3,4,5,7,9, };

	for (int i = 11; i <= 100; i++) {
		padovan[i] = padovan[i - 1] + padovan[i - 5];
	}
	
	int testCase, n;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		cin >> n;
		cout << padovan[n] << endl;
	}

	return 0;
}