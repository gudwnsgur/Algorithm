#include <iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int greatestCommonFactor = 0;
	int leastCommonMultiple = 0;
	int higherNumber = (A > B ? A : B);
	int lowNumber = (A > B ? B : A);

	while(1) {
		if ((higherNumber % A == 0) && (higherNumber % B == 0)) {
			leastCommonMultiple = higherNumber;
			break;
		}
		higherNumber++;
	}

	for (int i = lowNumber; i >= 1; i--) {
		if ( (A % i == 0) && (B % i == 0)) {
			greatestCommonFactor = i;
			break;
		}
	}
    
	cout << greatestCommonFactor << "\n";
	cout << leastCommonMultiple;
	return 0;
}