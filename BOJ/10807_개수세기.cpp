#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;


int main() {
	int n, v, res = 0;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec[i];
	cin >> v;

	for (int i = 0; i < n; i++) if (vec[i] == v) res++;
	cout << res << endl;
	return 0;
}
