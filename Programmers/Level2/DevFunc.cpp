#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer{ 1 };
	vector<int>days(progresses.size(), 0);
	for (int i = 0; i < progresses.size(); i++) {
		do {
			days[i]++;
			progresses[i] += speeds[i];
		} while (progresses[i] < 100);
	}
	for (int i = 0; i < progresses.size(); i++) {
		cout << days[i] << ' ';
	}
	int day = days[0];
	for (int i = 1, j = 0; i < days.size(); i++) {
		// day = 7
		if (days[i] <= day) {
			answer[j]++;
		}
		else {
			answer.push_back(1);
			j++;
			day = days[i];
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
	return answer;
}
int main() {
	vector<int> a = { 93,30,55 };
	vector<int> b = { 1, 30 , 5 };
	solution(a, b);
	return 0;
}