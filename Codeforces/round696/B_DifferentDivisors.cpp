#include <iostream>
using namespace std;

int main() {
	int testCase, d;
	cin >> testCase;
	while (testCase--) {
		cin >> d;
		int first = d + 1, second;
		for (first; first<=100000; first++) {
			bool primeNum = true;
			for (int i = 2; i < first; i++) {
				if (!(first%i)) {
					primeNum = false;
					break;
				}
			}
			if (primeNum) break;
		}

		second = first + d;
		for (second; second <= 100000; second++) {
			bool primeNum = true;
			for (int i = 2; i < second; i++) {
				if (!(second%i)) {
					primeNum = false;
					break;
				}
			}
			if (primeNum) break;
		}
		cout << first*second << endl;
	}
	return 0;
}

