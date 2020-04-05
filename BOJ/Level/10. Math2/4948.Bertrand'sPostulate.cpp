#include <iostream>
using namespace std;

bool primeNumber[123456 * 2 + 1]; //  [0] ~ [2n+1] 

int main() {
	int N;
	for (int i = 2; i <= 123456 * 2; i++) {
		primeNumber[i] = true;
	}
	for (int i = 2; i * i <= 123456 * 2; i++) {
		if (primeNumber[i]) {
			for (int j = i * i; j <= 123456 * 2; j += i)
				primeNumber[j] = false;
		}
	}
	while (cin >> N) {
		if (N == 0) break;
		int count = 0;

		for (int i = N + 1; i <= 2 * N; i++) {
			if (primeNumber[i]) count++;
		}
		cout << count << endl;
	}
	return 0;
}