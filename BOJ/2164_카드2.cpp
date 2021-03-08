#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++) q.push(i);

	while (q.size() != 1) {
		q.pop();
		int num = q.front();
		q.pop();
		q.push(num);
	}

	cout << q.front() << endl;
	return 0;
}

