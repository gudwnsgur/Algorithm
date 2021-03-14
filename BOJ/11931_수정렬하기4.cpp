#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#define endl '\n'
using namespace std;

int main() {
	int n, num;
	cin >> n;
	priority_queue<int> pq;
	while (n--) {
		cin >> num;
		pq.push(num);
	}
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
	return 0;
}

