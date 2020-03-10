#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string arrangement) {
	int answer = 0;
	stack<char> s;

	int a = 0;
	for (int i = 0; i < arrangement.size(); i++) {
		if (arrangement[i] == '(') {
			s.push('(');
		}
		else {
			s.pop();
			if (s.size() >=1 && arrangement[i-1]=='(') 
				answer += (s.size());
			else if(arrangement[i-1] == ')')
				answer += 1;
		}
	}
	return answer;
}
int main() {
	cout << solution("()(((()())(())()))(())");
	return 0;
}