#include <iostream>
using namespace std;

int main() {
	int N, M;
	int *arr;
	cin >> M >> N;

	arr = new int[N - M + 1];
	bool *isPrimeNum = new bool[N - M + 1];

	for (int i = 0; i < N - M + 1; i++) {
		arr[i] = M + i;
		isPrimeNum[i] = true;
		if (arr[i] == 1) isPrimeNum[i] = false;
		else {
			for (int j = 2; j < arr[i]; j++) {
				if (arr[i] % j == 0) isPrimeNum[i] = false;
			}
		}
	}

	int min = 10001, sum = 0;
	bool primeNumExisted = false;

	for (int i = 0; i < N - M + 1; i++) {
		if (isPrimeNum[i] == true) {
			if (arr[i] < min) min = arr[i];
			sum += arr[i];
			primeNumExisted = true;
		}
	}
	if (!primeNumExisted) cout << -1;
	else {
		cout << sum << endl;
		cout << min << endl;
	}


	return 0;
}