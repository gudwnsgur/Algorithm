#include <iostream>
using namespace std;

int fibonacci(int left, int right, int N) {
	if (N == 0) return left;
	else
		fibonacci(right, left + right, N - 1);
}

int main() {
	int N;
	cin >> N;
	int left = 0;
	int right = 1;

	cout << fibonacci(left, right, N);

	return 0;
}