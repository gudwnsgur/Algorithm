#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string answer = "";

bool check(string str) {
	stack<char> s;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ')' && s.empty()) {
			return false;
		}
		else if (str[i] == '(') s.push('(');
		else s.pop();
	}
	if (!s.empty()) return false;
	return true;
}

string recursion(string p) {
	if (p.size() == 0) return p;
	string u = "", v = "";
	int cnt = 0, i = 0;
	do {
		p[i] == '(' ? cnt++ : cnt--;
		u += p[i++];
	} while (cnt);

	for (; i < p.size(); i++) v += p[i];

	if (check(u)) return u + recursion(v);
	
	string tmp = "(";
	tmp += recursion(v) + ")";
	for (int i = 1; i < u.size() - 1; i++) {
		if (u[i] == '(') tmp += ')';
		else tmp += '(';
	}
	return tmp;
}

string solution(string p) {
	if (p.size() == 0) return p;

	answer = recursion(p);
	return answer;
}
int main() {
	cout << solution("()))((()");
	return 0;
}