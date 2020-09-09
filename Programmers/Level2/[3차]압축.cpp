#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
map<string, int> m;
int cnt = 27;
vector<int> solution(string msg) {
	vector<int> answer;
	for (int i = 0; i < 26; i++) {
		string str = "";
		str += (i + 65);
		m.insert(make_pair(str, i + 1));
	}
	for (int i = 0; i < msg.size(); i++) {
		string str= "";
		str += msg[i];
		int print = m.find(str)->second;
		bool existed = true;

		int j;
		for (j = i + 1; j < msg.size(); j++) {
			str += msg[j];
			if (m.find(str) != m.end()) {
				print = m.find(str)->second;
			}
			else {
				m.insert(make_pair(str, cnt++));
				existed = false;
				break;
			}
		}
		answer.push_back(print);
		if(!existed) i += str.size() - 2;
		if (j == msg.size()) break;
	}
	return answer;
}
int main() {
	m.insert(make_pair("A", 1));
	cout << (m.find("A") != m.end()); // 1 : 존재
	cout << (m.find("A") == m.end()); // 존재하면 0
	//solution("KAKAO");
	cout << endl << endl << endl << endl;
	//solution("TOBEORNOTTOBEORTOBEORNOT");
	return 0;
}