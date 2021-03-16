#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<int> result;
	result.push_back(v[0]);
	for (int i = 1; i < n; i++) {
		if (v[i] > result.back()) result.push_back(v[i]);
		else {
			int cur = result.size() - 1;
			while (cur >= 0 && result[cur] >= v[i]) cur--;
			result[cur + 1] = v[i];
		}
	}
	cout << result.size() << endl;
	return 0;
}
