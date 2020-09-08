#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> d;
int cnt = 0;
bool visited[8];
char friends1[8];
char arr[8];

bool promising(int len) {
	if (len == 0 || len == 1) return true;

	for (int i = 0; i < d.size(); i++) {
		int x = len, y = len;

		for (int j = 0; j < len; j++) {
			if (arr[j] == d[i][0]) x = j;
			if (arr[j] == d[i][2]) y = j;
		}
		if (x != len && y != len) {
			int diff = x < y ? y - x : x - y;
			diff--;
	
			if (d[i][3] == '=' && (diff != d[i][4] - 48)) return false;
			if (d[i][3] == '>' && (diff <= d[i][4] - 48)) return false;
			if (d[i][3] == '<' && (diff >= d[i][4] - 48)) return false;
		}

	}
	return true;
}

void dfs(int length, int m) {
	if (!promising(length)) return;
	if (length == m) {
		cnt++;
		return;
	}
	for (int i = 0; i < m; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[length] = friends1[i];
			dfs(length + 1, m);
			visited[i] = false;
		}

	}
}

int solution(int n, vector<string> data) {
	d = data;
	cnt = 0;
	string str = "ACFJMNRT";
	for (int i = 0; i < 8; i++) {
		visited[i] = false;
		friends1[i] = str[i];
	}
	dfs(0, 8);
	return cnt;
}
