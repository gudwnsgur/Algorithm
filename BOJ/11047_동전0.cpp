#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
	int n, k, coin, result=0;
	cin >> n >> k;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		cin >> coin;
		v.push_back(coin);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++) {
		if (k >= v[i]) {
			result += k / v[i];
			k = k%v[i];
		}
	}

	cout << result << endl;
	return 0;
}