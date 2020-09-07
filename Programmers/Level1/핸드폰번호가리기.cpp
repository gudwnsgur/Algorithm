#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
	int star = phone_number.size() > 4 ? phone_number.size()-4 : 0;
	string answer = "";
	for (int i = 0; i < star; i++) answer += "*";
	for (int i = star; i < phone_number.size(); i++) answer.push_back(phone_number[i]);
	return answer;
}