#include <iostream>
using namespace std;

int main() {
	int N, count = 0;
	int *arr;
	cin >> N;

	arr = new int[N];
	bool *isPrimeNum = new bool[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		isPrimeNum[i] = true;
		if (arr[i] == 1) isPrimeNum[i] = false;
		else {
			for (int j = 2; j < arr[i]; j++) {
				if (arr[i] % j == 0) isPrimeNum[i] = false;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (isPrimeNum[i] == true) count++;
	}
	cout << count;

	return 0;
}