#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[9];

void dfs(int length, int n, int m) {
	if (length == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl; 
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (i >= arr[length-1]) {
			arr[length] = i;
			dfs(length + 1, n, m);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	
	dfs(0, n, m);
	return 0;
}