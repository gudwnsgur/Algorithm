#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int arr[21];
int n, s, cnt = 0;


void solution(int length, int cur) {

	if (length == n) {
		if (s == cur) cnt++;
		return;
	}

	solution(length + 1, cur + arr[length]);
	solution(length + 1, cur);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];


	solution(0, 0);
	cout << (s ? cnt : cnt-1) << endl;
	return 0;
}
