#include <string>
#include <vector>
using namespace std;

string solution(string s) {
	string answer = "";
	answer += toupper(s[0]);

	for (int i = 1, wordIndex = 1; i < s.size(); i++, wordIndex++) {
		if (s[i - 1] == ' ') wordIndex = 0;
		answer += (wordIndex % 2 ? tolower(s[i]) : toupper(s[i]) );
	}
	cout << answer << endl;
	return answer;
}