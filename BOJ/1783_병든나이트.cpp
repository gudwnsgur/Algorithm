#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int solve(int n, int m) {
	int result = 1;
	if (n == 1) return 1;
	if (n == 2)  return (m < 7 ? (m + 1) / 2 : 4);

	int arr[8] = { 0, 1, 2, 3, 4, 4, 4, 5 };
	return (m < 8 ? arr[m] : m - 2);
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << solve(n, m) << endl;
	return 0;
}
