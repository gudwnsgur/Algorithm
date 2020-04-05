#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;

	string str;
	for (int i = 0; i < n; i++) {
		stack<char> s;
		bool VPS = true;
		cin >> str;
		if (str[0] != '(' || str[str.size() - 1] != ')') VPS = false;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') s.push('(');
			else {
				if (s.empty()) VPS = false;
				else s.pop();
			}
		}
		if (!s.empty()) VPS = false;

		if (!VPS) cout << "NO\n";
		else cout << "YES\n";

	}

	return 0;
}