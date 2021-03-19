#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#define endl '\n'
using namespace std;

set<char> s;
vector<char> menu, arr;
vector<bool> visited;
vector<string> order;
vector<string> answer;
vector<pair<int, string>> ans;



int count() {
	int cnt = 0;
	for (int i = 0; i < order.size(); i++) {
		int curCnt = 0;
		for (int j = 0; j < order[i].size(); j++) {
			for (int k = 0; k < arr.size(); k++) {
				if (order[i][j] == arr[k]) curCnt++;
			}
		}
		if (curCnt == arr.size()) cnt++;
	}
	return cnt;
}

void dfs(int length, int n, int m) {
	if (length == m) {
		string str = "";
		for (int i = 0; i < length; i++) str.push_back(arr[i]);
		int cnt = count();

		if(cnt != 0 && cnt != 1) ans.push_back({ cnt, str });
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (length == 0 || (length != 0 && arr[length - 1] < menu[i])) {
				arr[length] = menu[i];
				visited[i] = true;
				dfs(length + 1, n, m);
				visited[i] = false;
			}
		}
	}
}

bool compare(pair<int, string> a, pair<int, string> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

vector<string> solution(vector<string> orders, vector<int> course) {
	order = orders;
	for (int i = 0; i < orders.size(); i++) {
		for (int j = 0; j < orders[i].size(); j++) {
			if (s.find(orders[i][j]) != s.end()) continue;

			s.insert(orders[i][j]);
			menu.push_back(orders[i][j]);
		}
	}
	// menu : A B C D E F G H

	for (int i = 0; i < course.size(); i++) {
		ans.clear();
		arr = vector<char>(course[i]);
		visited = vector<bool>(menu.size());

		dfs(0, menu.size(), course[i]);
		
		if (ans.empty()) continue;

		sort(ans.begin(), ans.end(), compare);
		int curMax = ans[0].first;
		answer.push_back(ans[0].second);
		for (int i = 1; i < ans.size(); i++) {
			if (ans[i].first == curMax) answer.push_back(ans[i].second);
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}
