#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define endl '\n'
using namespace std;

queue<int> q[101];

int main() {
	int n, k, cnt = 0, s = 0;
	cin >> n >> k;
	bool end = false;
	vector<int> order(k), tab;
	for (int i = 0; i < k; i++) {
		cin >> order[i];

		if (tab.size() == n) {
			if (!end) {
				s = i;
				end = true;
			}
			q[order[i]].push(i);
		}
		else {
			bool put = true;
			for (int j = 0; j < tab.size(); j++) {
				if (order[i] == tab[j]) {
					put = false;
				}
			}
			if (put) {
				tab.push_back(order[i]);
			}
		}
	}
	if (!end) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i <= 100; i++) q[i].push(1000);

	for (int i = s; i < k; i++) {
		int cur = order[i];
		bool change = true;
		for (int j = 0; j < n; j++) {
			if (cur == tab[j]) {
				change = false;
				break;
			}
		}

		q[cur].pop();

		if (change) {
			cnt++;
			int tabIdx = -1, minNum = -1;
			for (int j = 0; j < n; j++) {
				if (q[tab[j]].front() > minNum) {
					tabIdx = j;
					minNum = q[tab[j]].front();
				}
			}
			tab[tabIdx] = cur;
		}
	}
	cout << cnt << endl;
	return 0;
}


