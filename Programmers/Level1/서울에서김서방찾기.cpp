#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<string> seoul) {
	string answer = "김서방은 ";
	int index = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
	answer += to_string(index);
	answer += "에 있다";

	return answer;
}