#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int no = 1;
	string str;
	stack<char> s;

	cin >> str;
	while (str.substr(0, 1) != "-") {
		int cnt = 0;
		for (int i = 0; i < str.size(); i++) 
		{
			if (str[i] == '{') {
				if (s.size() >= str.size() - i) {
					cnt++;
					s.pop();
				}
				else s.push('{');
			}

			else {
				if (s.empty()) {
					cnt++;
					s.push('{');
				}
				else s.pop();
			}
		}
		cout << no++ << ". " << cnt << endl;
		cin >> str;
	}

	return 0;
}

