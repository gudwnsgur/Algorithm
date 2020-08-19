#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[201] = { 0, };
int maxCnt = 0;
bool cnt[201] = { false, };
vector<int> v[201];

void checkCnt(int n) {
	int localCnt = 0;
	for (int i = 0; i < n; i++) {
		cnt[arr[i]] = true;
	}
	for (int i = 0; i < n; i++) {
		if (cnt[i]) localCnt++;
	}
	maxCnt = max(maxCnt, localCnt);

	for (int i = 0; i < n; i++) {
		cnt[i] = false;
	}
}

void dfs(int length, int n) {
	if (length == n) {
		checkCnt(n);
		return;
	}

	for (int i = 0; i < v[length].size(); i++) {
			arr[length] = v[length][i];
			dfs(length + 1, n);
	}
}

int main() {
	int cow, barn, n, number;
	cin >> cow >> barn;

	for (int i = 0; i < cow; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> number;
			v[i].push_back(number);
		}
	}

	dfs(0, cow);
	cout << maxCnt << endl;

	return 0;
}