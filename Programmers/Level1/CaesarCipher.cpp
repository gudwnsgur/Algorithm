#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, int n) {
	string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lowerCase = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 65 && s[i] <= 90) s[i] = upperCase[(s[i] - 65 + n) % 26];
		else if (s[i] >= 97 && s[i] <= 122) s[i] = lowerCase[(s[i] - 97 + n) % 26];
	}
	return s;
}
int main() {
	cout << solution("dn nw SDNJ n", 5);
}