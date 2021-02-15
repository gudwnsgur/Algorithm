#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<char> ch;
vector<string> answer, order;
vector<pair<string, int>> ans;
vector<int> courses, arr;
vector<bool> visited;

int promise() {
	int cnt = 0;
	// arr에 담긴 index로 ch에서 뽑아서 order에 몇개가 있는지 확인
	for (int i = 0; i < order.size(); i++) {
		int length = arr.size();
		for (int j = 0; j < order[i].size(); j++) {
			for (int k = 0; k < arr.size(); k++) {
				if (ch[arr[k]] == order[i][j]) length--;
			}
		}
		if (length == 0) cnt++;
	}
	return cnt;
}
void dfs(int length, int n, int r) {
	if (length == r) {
		int cnt = promise();
		if (cnt >= 2) {
			string str = "";
			for (int i = 0; i < arr.size(); i++) {
				str.push_back(ch[arr[i]]);
			}
			ans.push_back({ str, cnt });
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (length == 0 || (length != 0 && arr[length - 1] < i)) {
				visited[i] = true;
				arr[length] = i;
				dfs(length + 1, n, r);
				visited[i] = false;
			}
		}
	}
}

bool compare(pair<string, int> a, pair<string, int> b) {
	if (a.first.size() == b.first.size()) return a.second > b.second;
	return a.first.size() < b.first.size();
}

vector<string> solution(vector<string> orders, vector<int> course) {

	order = orders;
	courses = course;

	for (int i = 0; i < orders.size(); i++) {
		for (int j = 0; j < orders[i].size(); j++) {
			ch.push_back(orders[i][j]);
		}
	}
	sort(ch.begin(), ch.end());
	ch.erase(unique(ch.begin(), ch.end()), ch.end());


	for (int i = 0; i < course.size(); i++) {
		arr = vector<int>(course[i], 0);
		visited = vector<bool>(course[i], false);

		dfs(0, ch.size(), course[i]);
	}
	sort(ans.begin(), ans.end(), compare);
	int curCnt = 0;

	for (int i = 0; i < ans.size(); i++) {
		if (i == 0 || (i != 0 && ans[i - 1].first.size() != ans[i].first.size())) {
			curCnt = ans[i].second;
		}
		if (ans[i].second == curCnt) answer.push_back(ans[i].first);
	}
	sort(answer.begin(), answer.end());
	return answer;
}
