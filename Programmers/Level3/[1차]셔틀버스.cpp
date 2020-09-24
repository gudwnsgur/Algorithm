#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int result;
	sort(timetable.begin(), timetable.end());
	vector<int> crew, bus;

	for (int i = 0; i < timetable.size(); i++)
		crew.push_back(stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3, 2)));
	for (int i = 0, minute = 540; i < n; i++, minute += t)
		bus.push_back(minute);

	int curCrew = 0, lastCrew = 0;
	for (int i = 0; i < bus.size(); i++) {
		int curM = m;
		while (curM-- && curCrew < crew.size()) {
			if (crew[curCrew] > bus[i]) break;
			if (i == bus.size() - 1) lastCrew++;
			curCrew++;
		}
	}
	result = lastCrew == m ? crew[curCrew - 1] - 1 : bus[bus.size() - 1];

	answer += (result < 600 ? "0" : "");
	answer += to_string(result / 60);
	answer += ":";

	result %= 60;
	
	answer += (result < 10 ? "0" : "");
	answer += to_string(result);
	return answer;
}
