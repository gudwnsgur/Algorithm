#include <iostream>
#include <vector>
using namespace std;

bool visited[15] = { false, };
int arr[15] = { 0, };
int result = 0;

bool promising(int length, int n) {

	for (int i = 0; i < length - 1; i++) {
		if (arr[length - 1] - arr[i] == length - i - 1 ||
			arr[length - 1] - arr[i] == i - length + 1) {
			return false;
		}
	}
	return true;
}



void bfs(int length, int n) {

	if (promising(length, n)) {
		if (length == n) {
			result++;
	
			return;
		}

		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				arr[length] = i;
				bfs(length + 1, n);
				visited[i] = false;
			}
		}
	}

}

int main() {
	int n;
	cin >> n;

	bfs(0, n);
	cout << result << endl; 
	return 0;
}