#include <string>
#include <vector>
#include <queue>
#include <cctype>
#include <iostream>
#include <algorithm>
using namespace std;
int cnt[1000001] = { 0, };

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}
vector<int> solution(string s) {
	vector<string> a;
	vector<pair<int, int>> b;
	vector<int> answer;
	int maxNum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			string num="";
			while (isdigit(s[i])) {
				num += s[i];
				i++;
			}
			cnt[stoi(num)]++;
			maxNum = max(maxNum, stoi(num));
		}
	}
	for (int i = 1; i <= maxNum; i++) {
		if (cnt[i]) b.push_back(make_pair(cnt[i], i));
	}
	sort(b.begin(), b.end(), compare);

	for (int i = 0; i < b.size(); i++) {
		answer.push_back(b[i].second);
	}
	return answer;
}
int main() {
	solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
	return 0;
}