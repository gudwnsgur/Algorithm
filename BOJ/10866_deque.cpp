#include <iostream>
#include <deque>
#include <string>
#define endl '\n'
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		string op;
		cin >> op;
		if (op == "push_front") {
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (op == "push_back") {
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (op == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << endl;
				dq.pop_front();
			}
			else cout << "-1" << endl;
		}
		else if (op == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << endl;
				dq.pop_back();
			}
			else cout << "-1" << endl;
		}
		else if (op == "size") cout << dq.size() << endl;
		else if (op == "empty") cout << dq.empty() << endl;
		else {
			if (dq.empty()) cout << "-1" << endl;
			else cout << (op=="front" ? dq.front() : dq.back()) << endl;
		}
	}

	return 0;
}