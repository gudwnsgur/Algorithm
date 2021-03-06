#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	int sum = 0, minNum = 100;
	vector<int> num(7);
	for (int i = 0; i < 7; i++) {
		cin >> num[i];
		if (num[i] % 2) {
			sum += num[i];
			minNum = min(minNum, num[i]);
		}
	}
	sum == 0 ? (cout << -1 << endl) : (cout << sum << endl << minNum << endl);
	return 0;
}
