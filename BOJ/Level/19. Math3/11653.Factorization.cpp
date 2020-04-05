#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	do {
		for (int i = 2; i <= N; i++) {
			if (N % i == 0) {
				cout << i << "\n";
				N /= i;
				break;
			}
		}
	} while (N != 1);
	return 0;
}