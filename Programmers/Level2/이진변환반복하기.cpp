#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer(2, 0);
	while (s.size() != 1 || s[0] != '1') {
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') cnt++;
		}
		answer[1] += s.size() - cnt;

		s = "";
		while (cnt > 0) {
			s.push_back(cnt % 2 + 48);
			cnt /= 2;
		}
		answer[0]++;
	}
	return answer;
}
int main() {
	solution("110010101001");
	return 0;
}
