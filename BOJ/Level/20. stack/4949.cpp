#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string str;
	while (1) {
		getline(cin, str);
		if (str == ".") break;
		stack<char> s;	bool isCorrect = true;
	
		for (int i = 0; i < str.size(); i++) 
		{
			if (str[i] == '[') s.push('[');
			else if (str[i] == '(') s.push('(');
			else if (str[i] == ']') {
				if (s.empty() || s.top()!='[') isCorrect = false;
				else s.pop();
			}
			else if (str[i] == ')') {
				if (s.empty() || s.top() != '(') isCorrect = false;
				else s.pop();
			}
		}
		if (s.empty() && isCorrect) cout << "yes\n";
		else cout << "no\n";

	}
	return 0;
}