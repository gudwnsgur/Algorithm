#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<string> a, vector<string> b) {
	return a.back() < b.back();
}

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	vector<pair<int, string>> type;
	sort(clothes.begin(), clothes.end(), cmp);
	type.push_back(make_pair(2, clothes[0][1]));

	for (int i = 1; i < clothes.size(); i++) {
		if (clothes[i][1] == type.back().second) type.back().first++;
		else type.push_back(make_pair(2, clothes[i][1]));
	}
	for (int i = 0; i < type.size(); i++) answer *= type[i].first;

	return answer-1;
}
// 경우의 수 공식 => (a+1)(b+1)(c+1)...(z+1) -1  