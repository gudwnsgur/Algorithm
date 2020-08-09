#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
	int n, time, result=0;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		cin >> time;
		v.push_back(time);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 0; i < v.size(); i++) {
		result += v[i] * (i + 1);
	}

	cout << result << endl;
	return 0;
}