#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;

int arr[4] = {2, 0, 2, 0};

void solve(int n) {
	if (n < 4) {
		cout << "NO" << endl;
		return;
	}

	string str;
	int left = 0, right = 0;
	cin >> str;
	for (int i = 0; i < 4; i++) {
		if (arr[i] != str[i] - 48) break;
		left++;
	}
	
	for (int i = n-1; i > n-5; i--) {
		if (arr[i-n+4] != str[i] - 48) break;
		right++;
	}
	cout << (left + right >= 4 ? "YES" : "NO") << endl;
	return;
}

int main() {
	int testCase, n;
	cin >> testCase;
	while (testCase--) {
		cin >> n;
		solve(n);
	}
	return 0;
}
