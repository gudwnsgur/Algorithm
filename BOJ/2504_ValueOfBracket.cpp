#include <iostream>
#include <stack>
#include <string>
#define endl '\n'
using namespace std;
stack<char> s;


int solution(string str) {
	if (str[0] == ')' || str[0] == ']') return 0;
	int cur = 1;
	long long result = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push('(');
			cur *= 2;
		}
		else if (str[i] == '[') {
			s.push('[');
			cur *= 3;
		}
		else if (str[i] == ')' && (s.empty() || s.top() != '(')) return 0;
		else if (str[i] == ']' && (s.empty() || s.top() != '[')) return 0;

		else if (str[i] == ')') {
			if (str[i - 1] == '(') result += cur;
			cur /= 2;
			s.pop();
		}
		else if (str[i] == ']') {
			if (str[i - 1] == '[') result += cur;
			cur /= 3;
			s.pop();
		}
	}
	if (!s.empty()) return 0;
	return result;
}

int main() {
	string str;
	cin >> str;
	cout << solution(str) << endl;
	return 0;
}