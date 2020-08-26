#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;
	vector<int> cmp(n);
	for (int i = 0; i < n; i++) cin >> cmp[i];

	cin >> m;
	vector<int> arr(m);
	vector<bool> existed(m);
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		existed[i] = false;
	}
	sort(cmp.begin(), cmp.end());

	for (int i = 0; i < arr.size(); i++) {
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (arr[i] == cmp[mid]) {
				existed[i] = true;
				break;
			}
			else if (arr[i] < cmp[mid]) right = mid - 1;
			else left = mid + 1;
		}
	}

	for (int i = 0; i < m; i++) cout << existed[i] << ' ';
	cout << endl;

	return 0;
}