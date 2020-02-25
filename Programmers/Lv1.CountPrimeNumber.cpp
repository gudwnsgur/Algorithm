#include <iostream>
using namespace std;

int solution(int n) {
	if (n == 0 || n == 1) return 0;

	int cnt = 0;
	bool* primeNumber = new bool[n + 1];
	for (int i = 2; i <= n; i++) {
		primeNumber[i] = true;
	}
	for (int i = 2; i <= n; i++) {
		if (primeNumber[i]) {
			for (int j = i * i; j <= n; j += i)
				primeNumber[j] = false;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (primeNumber[i]) cnt++;
	}
	return cnt;
}

int main() {
	int num;
	cin >> num;
	cout << solution(num);
	return 0;
}