#include <iostream>
using namespace std;

int GDC(int a, int b) {
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int A1, B1, A2, B2;
	cin >> A1 >> B1 >> A2 >> B2;
	int denominator = B1*B2, numerator = A1*B2 + A2*B1;
	int a1, b1, a2, b2;
	cout << numerator / GDC(numerator,denominator) << ' ' << denominator / GDC(numerator, denominator) << endl;
	return 0;
}
