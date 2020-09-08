#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	if (s[0] >= 'a' && s[0] <= 'z') answer += toupper(s[0]);
	else answer += s[0];

	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == ' ') {
			if (s[i] >= 'a' && s[i] <= 'z') answer += toupper(s[i]);
			else answer += s[i];
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') answer += tolower(s[i]);
		else answer += s[i];
	}
	return answer;
}