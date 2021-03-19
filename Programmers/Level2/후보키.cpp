#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int cnt = 0;
vector<int> rel, arr; 
vector<bool> visited;
vector<string> result;
vector<vector<string>> relations;
// 0 1 2 3

bool minimality(string str) {
	// result(이전까지 모은 속성) 와 str 비교
	for (int i = 0; i < result.size(); i++) {
		// result[i] == AB   str == AC ABC ADE ABCD DE
		int  cnt = 0;
		for (int j = 0; j < result[i].size(); j++) {
			for (int k = 0; k < str.size(); k++) {
				if (result[i][j] == str[k]) cnt++;
			}
		}
		if (cnt == result[i].size()) return false;
	}
	return true;
}
bool uniqueness() {
	set<vector<string>> s;
	vector<string> tmp;
	for (int i = 0; i < relations.size(); i++) {
		tmp.clear();
		for (int j = 0; j < arr.size(); j++) {
			tmp.push_back(relations[i][arr[j]]);
		}
		if (s.find(tmp) != s.end()) return false;
		s.insert(tmp);
	}
	return true;
}

void dfs(int length, int n, int m) {
	if (length == m) {
		if (!uniqueness()) return;
		string str = "";
		for (int i = 0; i < arr.size(); i++) str.push_back(arr[i] + 65);
		
		if (result.empty() || minimality(str)) {
			cout << str << ' ';
			cnt++;
			result.push_back(str);
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (length == 0 || (length != 0 && arr[length - 1] < rel[i])) {
				arr[length] = rel[i];
				visited[i] = true;
				dfs(length + 1, n, m);
				visited[i] = false;
			}
		}
	}
}
int solution(vector<vector<string>> relation) {
	relations = relation;
	for (int i = 0; i < relation[0].size(); i++) rel.push_back(i);

	for (int i = 1; i <= rel.size() ; i++) {
		arr = vector<int>(i);
		visited = vector<bool>(rel.size(), false);
		dfs(0, rel.size(), i);
	}
	return cnt;
}
