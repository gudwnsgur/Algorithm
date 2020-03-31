#include <iostream>
#include <stack>
#include <string>
#include <istream>
using namespace std;

int main() {
	int n;
	cin >> n;

	string str;
	stack<int> s;

	for (int i = 0; i < n; i++)	{
		cin >> str;

		if (str == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (str == "pop") {
			if (s.empty()) cout << "-1\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (str == "size") cout << s.size() << "\n";
		else if (str == "empty") cout << s.empty() << "\n";
		else {
			if (s.empty()) cout << "-1\n";
			else cout << s.top() << "\n";
		}
	}

	// push, pop, size, empty, top
	return 0;
}