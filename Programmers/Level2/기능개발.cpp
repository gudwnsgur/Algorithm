#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> day;
	for (int i = 0; i < progresses.size(); i++) {
		int d = ((100 - progresses[i]) % speeds[i]) ? (100 - progresses[i]) / speeds[i] +1 : (100 - progresses[i]) / speeds[i] ;
		day.push_back(d);
	}
	int cur = day[0];
	answer.push_back(1);
	for (int i = 1; i < day.size(); i++) {
		if (cur >= day[i]) answer.back()++;
		else {
			answer.push_back(1);
			cur = day[i];
		}
	}
	return answer;
}