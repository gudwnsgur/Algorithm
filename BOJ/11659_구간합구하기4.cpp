#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define endl '\n'
using namespace std;


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> num(n+1, 0), result(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		result[i] = result[i - 1] + num[i];
	}
	int s, e;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << result[e] - result[s - 1] << endl;
	}
	return 0;
}


