#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;


int main() {
	int n, x, cnt=0;

	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)  cin >> v[i];
	cin >> x;

	sort(v.begin(), v.end());
	int left = 0, right = v.size()-1;


	while (left < right) {
		if (v[left] + v[right] > x) right--;
		else if (v[left] + v[right] < x) left++;
		else {
			cnt++;
			left++;
			right--;
		}
	}


	cout << cnt << endl;
	return 0;
}
