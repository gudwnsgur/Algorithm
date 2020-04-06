#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer = 0;
bool visited[10]{ false , };
int arr[10]{ 0, };
int n, m;

void dfs(int length) {
	if (length == m) {
		for (int i = 0; i < length; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && i>arr[length-1]) {
			visited[i] = true;
			arr[length] = i;
			dfs(length+1);
			visited[i] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	dfs(0);
	return 0;
}