#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
	int size = number.size() - k;
	string answer = "";
	int s_index = 0;

	for (int i = 0; i < size; i++) {
		int cur = s_index;
		char ch = number[s_index];
		for (int j = s_index; j <= k+i ; j++) {
			if (number[j] > ch) {
				ch = number[j];
				cur = j;
			}
		}
		answer += ch;
		s_index = cur+1;
	}
	return answer;
}
int main() {
	cout << solution("1231234", 3);
	return 0;
}