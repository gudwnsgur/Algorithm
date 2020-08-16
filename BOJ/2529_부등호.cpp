#include <iostream>
#include <vector>
using namespace std;

bool visited[10] = { false , };
int arr[10] = { 0, };
int cnt = 0;
bool minDone = false, maxDone = false;

bool checkTrue(vector<char> v) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == '<' && arr[i] > arr[i + 1]) return false;
		if (v[i] == '>' && arr[i] < arr[i + 1]) return false;
	}
	return true;
}

void minBFS(int length, int n, vector<char> v) {
	if (minDone) return;

	if (length == n) {
		if (checkTrue(v)) {
			minDone = true;
			for (int i = 0; i < n; i++) cout << arr[i];
			cout << endl;
		}
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[length] = i;
			minBFS(length + 1, n, v);
			visited[i] = false;
		}
	}
}

void maxBFS(int length, int n, vector<char> v) {
	if (maxDone) return;

	if (length == n) {
		if (checkTrue(v)) {
			maxDone = true;
			for (int i = 0; i < n; i++) cout << arr[i];
			cout << endl;
		}
		return;
	}
	for (int i = 9; i >= 0; i--) {
		if (!visited[i]) {
			visited[i] = true;
			arr[length] = i;
			maxBFS(length + 1, n, v);
			visited[i] = false;
		}
	}
}
int main() {
	int n;
	vector<char> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		v.push_back(c);
	}

	maxBFS(0, n + 1, v);
	minBFS(0, n + 1, v);

}

// 6 7 8 9 3 4 5 0 2 1

// S=U / 4 U/ 1 D/ 2 U/ 1 D/ 1U / 1D
 // 6789 3 45 1 2 0