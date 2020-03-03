#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
	int index = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') index = 1;
		else {
			if (index % 2 == 0) s[i] = tolower(s[i]);
			else s[i] = toupper(s[i]);
			index++;
		}
	}
	return s;
}
int main() {
	cout << solution("ascvaCSNDJV maskNVdk ANSc");
	return 0;
}