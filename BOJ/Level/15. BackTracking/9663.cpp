#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 0;
int arr[15];

bool promising(int length) {
	for (int i = 0; i < length - 1; i++) {
		if (i != length-1) {
			if (arr[i] == arr[length-1]) return false;
			if ( (length-1) - i == arr[length-1] - arr[i] || 
				i - (length-1) == arr[length-1] - arr[i]) 
				return false;

		}
	}
	return true;
}

void dfs(int length, int n) {
	if (promising(length)) {
		if (length == n) {
			answer++;
			/*
			for (int i = 0; i < n; i++) {
				cout << arr[i] << ' ';
			}
			cout << endl;
			*/
			return;
		}
		for (int i = 1; i <= n; i++) {
			arr[length] = i;
			dfs(length + 1, n);
		}
	}
}

int main() {
	int n;
	cin >> n;
	dfs(0, n);
	cout << answer;
	return 0;
}