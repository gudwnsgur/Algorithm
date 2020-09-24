#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[8] = { false, };
string result[8] = { "", };
vector<string> user, ban;
vector<vector<string>> res;
int cnt = 0;

void dfs(int length, int n) {
	if (length == n) {
		bool existed = false;
		vector<string> tmp;
		int curCnt = 0;
		for (int i = 0; i < n; i++) tmp.push_back(result[i]);
		sort(tmp.begin(), tmp.end());
		for (int i = 0; i < res.size(); i++) {
			curCnt = 0;
			if (res[i].size() == tmp.size()) {
				for (int j = 0; j < tmp.size(); j++) {
					if (res[i][j] == tmp[j]) curCnt++;
				}
			}
			if (curCnt == tmp.size()) return;
		}
		res.push_back(tmp);
		cnt++;
		return;
	}

	for (int i = 0; i < user.size(); i++) {
		if (!visited[i] && user[i].size() == ban[length].size()) {
			bool possible = true;
			for (int j = 0; j < user[i].size(); j++) {
				if (ban[length][j] != '*' && ban[length][j] != user[i][j]) possible = false;
			}
			if (possible) {
				visited[i] = true;
				result[length] = user[i];
				dfs(length + 1, n);
				visited[i] = false;
			}
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	if (user_id.size() == banned_id.size()) return 1;
	user = user_id, ban = banned_id;

	dfs(0, ban.size());
	return cnt;
}