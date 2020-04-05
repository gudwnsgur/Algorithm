#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> loc(N, vector<int>(2, 0));
	for (int i = 0; i < N; i++) {
		cin >> loc[i][1] >> loc[i][0];
	}

	sort(loc.begin(), loc.end());
	for (int i = 0; i < N; i++) {
		cout << loc[i][1] << " " << loc[i][0] << "\n";
	}
	return 0;
}