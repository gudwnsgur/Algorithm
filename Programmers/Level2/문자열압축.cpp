#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s) {
	int answer = s.size();

	for (int i = 1; i <= s.size() / 2; i++) {
		string str = s.substr(0, i);
		int length = i;
		int knoting = 0;

		for (int j = i; j < s.size(); j += i) {

			if (!str.compare(s.substr(j, i)))
				knoting++;

			else {
				if (knoting) {
					knoting++;
					while (knoting > 0) {
						length++;
						knoting /= 10;
					}
				}
				knoting = 0;
				str = s.substr(j, i);
				length += str.size();
			}
		}
		if (knoting) {
			knoting++;
			while (knoting > 0) {
				length++;
				knoting /= 10;
			}
		}
		answer = min(answer, length);
	}
	return answer;
}