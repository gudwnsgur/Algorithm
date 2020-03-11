#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s) {
	int answer = 10001;
	for (int i = 1; i <= s.size() / 2; i++) {
		int cnt = 1;
		string sub = s.substr(0, i);
		string cmp, cmp2;


		for (int j = i; j < s.size(); j += i) {
			int c = 0;
			cmp = s.substr(j, i);

			if (sub == cmp)	cnt++;
			else {
				if (cnt == 1) {
					cmp2 += sub;
					sub = cmp;
				}else {
					cmp2 = cmp2 + to_string(cnt) + sub;
					sub = cmp;
					cnt = 1;
				}
			}

			if (j + i >= s.length()) {  
				if (cnt != 1) {
					cmp2 = cmp2 + to_string(cnt) + sub;
					break;
				}
				else {
					cmp2 = cmp2 + s.substr(j);
					break;
				}
			}
		}
		answer = (answer > cmp2.length()) ? cmp2.length() : answer;
	}
	return answer;
}
int main() {
	cout << solution("aabbaccc");
	return 0; 
}