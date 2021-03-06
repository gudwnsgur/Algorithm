#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	int sum = 0;
	vector<int> num(5);
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
		sum += num[i];
	}
	sort(num.begin(), num.end());
	cout << sum / 5 << endl << num[2] << endl;
	return 0;
}
