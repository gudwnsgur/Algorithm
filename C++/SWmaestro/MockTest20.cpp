// 근묵자흑
// Birds of a feather flock together

#include <iostream>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;

	int* numbers = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}   

	int cnt = 1;
	n -= k;
	while (n > 0) {
		cnt++;
		n -= (k - 1);
	}
	cout << cnt;

	return 0;
}