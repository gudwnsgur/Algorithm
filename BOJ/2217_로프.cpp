#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define endl '\n'
using namespace std;


int main() {
	int n, result, cnt = 1;
	cin >> n;
	vector<int> rope(n);
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}
	sort(rope.begin(), rope.end(), greater<int>());
	result = rope[0];

	for (int i = 1; i < n; i++) {
		result = max(result, rope[i] * (i + 1));
	}
	cout << result << endl;
	return 0;
}


