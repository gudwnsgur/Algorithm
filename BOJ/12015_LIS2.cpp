#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<int> lis;
int n, inf= -987654321;

int main() {
	cin >> n;
	lis.push_back(inf);

	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (lis.back() < cur) lis.push_back(cur);
		else lis[lower_bound(lis.begin(), lis.end(), cur) - lis.begin()] = cur;
	}
	cout << lis.size() - 1 << endl;
	return 0;
}
