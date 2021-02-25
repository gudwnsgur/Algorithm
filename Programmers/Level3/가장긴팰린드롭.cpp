#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int solution(string s)
{
	int answer = 1;
	for (int i = 1; i < s.size() - 1; i++) {
		int cnt = 1, left = i - 1, right = i + 1;
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			cnt += 2;
			left--;
			right++;
		}
		answer = max(answer, cnt);
	}

	for (int i = 1; i < s.size(); i++) {
		int cnt = 0, left = i - 1, right = i;
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			cnt += 2;
			left--;
			right++;
		}
		answer = max(answer, cnt);
	}
	return answer;
}

int main() {
	while (true) {
		string str;
		cin >> str;
		solution(str);
		cout << endl;
	}
	return 0;
}
