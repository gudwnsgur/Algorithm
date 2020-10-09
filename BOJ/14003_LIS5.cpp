#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<int> arr, lis, index, result;
int n, inf = -1000000001;
int main() {
	cin >> n;
	index = vector<int>(n);
	arr = vector<int>(n);
	lis.push_back(inf);

	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		arr[i] = cur;
		if (lis.back() < cur) {
			index[i] = lis.size();
			lis.push_back(cur);
		}
		else {
			int curIndex = lower_bound(lis.begin(), lis.end(), cur) - lis.begin();
			lis[curIndex] = cur;
			index[i] = curIndex;
		}
	}
	int s = lis.size()-1;
	for (int i = n - 1; i >= 0; i--) {
		if (index[i] == s) {
			s--;
			result.push_back(arr[i]);
		}
	}
	cout << lis.size() - 1 << endl;
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << ' ';
	}cout << endl;
	return 0;
}