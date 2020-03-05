#include <iostream>
using namespace std;

int calculatePrice(int a, int b) {
	int aPrice = 0, bPrice = 0;
	
	if (a == 1) aPrice = 5000000;
	else if (a == 2 || a == 3) aPrice = 3000000;
	else if (a >= 4 && a <= 6) aPrice = 2000000;
	else if (a >= 7 && a <= 10) aPrice = 500000;
	else if (a >= 11 && a <= 15) aPrice = 300000;
	else if (a >= 16 && a <= 21) aPrice = 100000;

	if (b == 1) bPrice = 5120000;
	else if (b == 2 || b == 3) bPrice = 2560000;
	else if (b >= 4 && b <= 7) bPrice = 1280000;
	else if (b >= 8 && b <= 15) bPrice = 640000;
	else if (b >= 16 && b <= 31) bPrice = 320000;

	return aPrice+bPrice;
}

int main() {
	int testCase;
	int a, b;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> a >> b;
		cout << calculatePrice(a, b) << "\n";
	}
	return 0;
}
