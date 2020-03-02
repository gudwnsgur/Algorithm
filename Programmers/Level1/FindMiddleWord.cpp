#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
	string answer = "";

	if(s.size() % 2 == 0 ) answer.push_back(s[s.size() / 2 - 1]);
	answer.push_back(s[s.size() / 2 ]);

	return answer;
}

// only for test
int main() {
	string str = "abcdedasved";
	cout << solution(str);
	return 0;
}