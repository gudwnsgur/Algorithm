#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	cout << checkSequence(N);
    return 0; 
}

int checkSequence(int N) {
	if (N < 100) return N;
	if (N == 1000) N = 999;

	int count = 99;
	for (int i = 100; i <= N; i++) {
		if (((i / 100) - ((i / 10) % 10)) == (((i / 10) % 10) - (i % 10))) {
			count++;
		}
	}
	return count;
}