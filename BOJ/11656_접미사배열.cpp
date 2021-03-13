#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <functional>
#define endl '\n'
#define ll  long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	priority_queue<string, vector<string>, greater<string>> pq;

	for (int i = 0, j = str.size(); i < str.size(); i++, j--) {
		pq.push(str.substr(i, j));
	}
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}

