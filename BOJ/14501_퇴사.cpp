#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n;
int work[2][20]; // time, price
bool choice[20] = { false, };
int maxPrice = 0;

int calculatePrice() {
	int localPrice = 0;
	for (int i = 0; i < n; i++)
		localPrice += (choice[i] * work[1][i]);
	return localPrice;
}

void dfs(int length, int time, int n) {
	if (length == n) {
		maxPrice = max(maxPrice, calculatePrice());
		return;
	}
	if (!time) {
		choice[length] = false;
		dfs(length + 1, 0, n);
		// time available + not work
		if (length + work[0][length] <= n) {
			choice[length] = true;
			dfs(length + 1, work[0][length] - 1, n);
			// time available + work
		}
	}
	else {
		choice[length] = false;
		dfs(length + 1, time - 1, n);
		// time unavailable + not work
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> work[0][i] >> work[1][i];
	}
	dfs(0, 0, n);
	cout << maxPrice << endl;
	return 0;
}