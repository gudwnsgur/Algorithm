#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;


void solveEven(int n) {
	vector<int> a(n);
	for (int i = 1; i < n; i+= 2) {
		cin >> a[i-1] >> a[i];
		cout << a[i] << ' ' << a[i - 1] * -1 << ' ';
	}
	cout << endl;
	return;
}

int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n;
		cin >> n;
		solveEven(n);
	}
	return 0;
}
