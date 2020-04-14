#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
	string answer = "";
	vector<int> ans;
	for (int i = 0; i < s.size(); i++) {
		string str = "";
		while (s[i] != ' ' && i != s.size()) {
			str += s[i];
			i++;
		}
		ans.push_back(stoi(str));
	}
	sort(ans.begin(), ans.end());
	answer += to_string(ans[0]);
	answer += " ";
	answer += to_string(ans[ans.size() - 1]);
	return answer;
}
int main () {
	cout << solution("1 2 -3 -4");
	return 0;
}