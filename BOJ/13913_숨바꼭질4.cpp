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
	if (n >= k) {
		cout << n - k << endl;
		for (int i = n; i >= k; i--) cout << i << ' ';
		cout << endl;
		return 0;
	}
	
	int cnt = 0;
	queue<vector<int>> q;
	q.push({ n });
	visited[n] = true;

	while (!q.empty()) {
		int size = q.size();
		for (int s = 0; s < size; s++) {
			vector<int> tmp = q.front();

			if (tmp.back() == k) {
				cout << cnt << endl;
				for (int i = 0; i < tmp.size(); i++) {
					cout << tmp[i] << ' ';
				}cout << endl;
				return 0 ;
			}

			if (tmp.back()*2 <= MAX && !visited[tmp.back() * 2]) {
				visited[tmp.back() * 2] = true;
				tmp.push_back(tmp.back() * 2);
				q.push(tmp);
				tmp.pop_back();
			}
			if (tmp.back() -1 <= MAX && tmp.back() > 0 && !visited[tmp.back()-1]) {
				visited[tmp.back() -1] = true;
				tmp.push_back(tmp.back() -1);
				q.push(tmp);
				tmp.pop_back();
			}
			if (tmp.back() +1 <= MAX && !visited[tmp.back() +1]) {
				visited[tmp.back() +1] = true;
				tmp.push_back(tmp.back() +1);
				q.push(tmp);
				tmp.pop_back();
			}
			q.pop();
		}
		cnt++;

	}

	return 0;
}

