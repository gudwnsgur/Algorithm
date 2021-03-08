#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	string op, num;
	deque<int> dq;
	int n;
	while (tc--) {
		dq.clear();
		bool err = false, head = true;
		cin >> op >> n >> num;

		for (int i = num.size() - 1; i >= 0; i--) {
			if (num[i] < '0' || num[i] > '9') continue;
			int number = 0, digit = 1;
			while (num[i] >= '0' && num[i] <= '9') {
				number += (num[i] - '0') * digit;
				digit *= 10;
				i--;
			}
			dq.push_front(number);
		}

		for (int i = 0; i < op.size(); i++) {
			if (op[i] == 'R') head = (head ? 0 : 1);
			else {
				if (dq.empty()) {
					err = true;
					cout << "error" << endl;
					break;
				}
				else head ? dq.pop_front() : dq.pop_back();
			}
		}


		if (!err) {
			cout << "[";
			if (!dq.empty()) {
				if (head) {
					for (int i = 0; i < dq.size() - 1; i++) cout << dq[i] << ',';
					cout << dq[dq.size() - 1];
				}
				else {
					for (int i = dq.size() - 1; i > 0; i--) cout << dq[i] << ',';
					cout << dq[0];
				}
			}
			cout << "]" << endl;
		}
	}
	return 0;
}

