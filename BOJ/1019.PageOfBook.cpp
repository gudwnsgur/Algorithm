#include <iostream>
using namespace std;

void checkPage(int n, int* cnt) {
	while (n > 0) {
		cnt[n % 10]++;
		n /= 10;
	}
}

int main() {
	int* cnt = new int[10];
	for (int i = 0; i < 10; i++) cnt[i] = 0;

	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		checkPage(i, cnt);
	}

	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}
