#include <string>
#include <vector>

using namespace std;

string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string lower = "abcdefghijklmnopqrstuvwxyz";

string solution(string s, int n) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')  s[i] = upper[(s[i] - 'A' + n) % 26];
		else if(s[i] >= 'a' && s[i] <= 'z')  s[i] = lower[(s[i] - 'a' + n) % 26];
	}
	return s;
}