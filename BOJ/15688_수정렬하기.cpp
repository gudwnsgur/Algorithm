#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) cout << v[i] <<  endl;

	return 0;
}


