#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100001
#define endl '\n'
using namespace std;
vector<bool> visited(MAX + 1, false);

int n, k;

int main() {
	cin >> n >> k;


	queue<int> q;
	while (n <= MAX && !visited[n]) {
		if (n == k) {
			cout << 0 << endl;
			return 0;
		}
		visited[n] = true;
		q.push(n);
		n *= 2;
	}
	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int num = q.front();
			int left = num - 1, right = num + 1;
			while (left >= 0 && left <= MAX && !visited[left]) {
				if (left == k) {
					cout << cnt + 1 << endl;
					return 0;
				}
				visited[left] = true;
				q.push(left);
				left *= 2;
			}

			while (right <= MAX && !visited[right]) {
				if (right == k) {
					cout << cnt + 1 << endl;
					return 0;
				}
				visited[right] = true;
				q.push(right);
				right *= 2;
			}
			q.pop();
		}
		cnt++;
	}
	return 0;
}

