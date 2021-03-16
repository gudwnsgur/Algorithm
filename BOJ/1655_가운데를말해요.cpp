#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	priority_queue<int> minPQ;
	priority_queue<int, vector<int>, greater<int>> maxPQ;

	cin >> n;
	while (n--) {
		cin >> num;
		if (minPQ.size() == 0) minPQ.push(num);
		else if (maxPQ.size() == 0) {
			if (minPQ.top() > num) {
				int tmp = minPQ.top();
				minPQ.pop();
				minPQ.push(num);
				maxPQ.push(tmp);
			}
			else maxPQ.push(num);
		}

		else if (minPQ.size() == maxPQ.size()) {
			if (num > maxPQ.top()) {
				int tmp = maxPQ.top();
				maxPQ.pop();
				minPQ.push(tmp);
				maxPQ.push(num);
			}
			else minPQ.push(num);
		}

		else {
			if (num < minPQ.top()) {
				int tmp = minPQ.top();
				minPQ.pop();
				maxPQ.push(tmp);
				minPQ.push(num);
			}
			else maxPQ.push(num);
		}
		cout << minPQ.top() << endl;
	}

	return 0;
}

