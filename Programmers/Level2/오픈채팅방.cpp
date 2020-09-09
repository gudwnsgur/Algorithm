#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<string, string> m;
int n;

vector<string> solution(vector<string> record) {
	n = record.size();
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		string uid = "", name = "";
		int start =  (record[i][0] == 'C' ) ? 7 : 6;
		for (start; record[i][start] != ' ' && start<record[i].size() ; start++) {
			uid += record[i][start];
		}
		start++;
		for (start; start < record[i].size(); start++) {
			name += record[i][start];
		}
		if (record[i][0] != 'L') {
			if (m.count(uid)) m.erase(uid);
			m.insert(make_pair(uid, name));
		}
	}

	for (int i = 0; i < n; i++) {
		if (record[i][0] != 'C') {
			string uid = "";
			int start = (record[i][0] == 'C') ? 7 : 6;
			for (start; record[i][start] != ' ' && start<record[i].size(); start++) {
				uid += record[i][start];
			}
			
			string ans = "";
			ans += m.find(uid)->second;
		
			if (record[i][0] == 'E') ans += "님이 들어왔습니다.";
			else ans += "님이 나갔습니다.";
			answer.push_back(ans);
		}
	}

	return answer;
}
int main() {
	vector<string> v{ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	solution(v);
	return 0;
}