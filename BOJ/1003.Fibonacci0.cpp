#include <iostream>
using namespace std;

int fibonacci[41] = { 0, };

void solution() {
	fibonacci[0] = 0; fibonacci[1] = 1;
	for (int i = 2; i <= 40; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
}

int main() 
{	
	solution();

	int testCase, n;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> n;
		if (n == 0) cout << "1 0\n";
		else cout << fibonacci[n - 1] << ' ' << fibonacci[n] << "\n";
	}
	return 0;
}