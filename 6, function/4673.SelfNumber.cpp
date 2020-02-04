#include <iostream>
using namespace std;

int d(int n) {
	int number = n;
	do {
		number += n % 10;
		n = n / 10;
	} while (n >= 1);
	if (number > 10000) return 0;
	return number;
}

int main() {
	bool *arr = new bool[10001];
	
	for (int i = 0; i <= 10000; i++) {
		arr[i] = true;
	}

	for(int i=1 ; i<=10000; i++) {
		arr[d(i)] = false;
		if(arr[i] == true)
			cout << i << "\n";
	}

	return 0;
}