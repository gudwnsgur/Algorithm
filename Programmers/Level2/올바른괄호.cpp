#include <string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
	stack<char> st;
	if (s[0] != '(' || s[s.size() - 1] != ')') return false;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') st.push('(');
		else {
			if (st.empty()) return false;
			else st.pop();
		}
	}

	return st.empty();
}

// testCase
int main() {
	cout << solution("()()(())");
	return 0;
}