#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string airport[10002] = { "ICN", };
string ticket[10002][2];
bool visited[10002] = { false, };
vector<string> answer;
bool isFinished = false;

void dfs(int length, int n) {
	if (!isFinished) {
		if (length == n) {
			for (int i = 0; i <= n; i++)
				answer.push_back(airport[i]);
			isFinished = true;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!airport[length].compare(ticket[i][0])) {
				if (!visited[i]) {
					visited[i] = true;
					airport[length + 1] = ticket[i][1];
					dfs(length + 1, n);
					visited[i] = false;
				}
			}
		}
	}
}

bool compare(vector<string> a, vector<string> b) {
	return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> tickets) {
	sort(tickets.begin(), tickets.end());
	for (int i = 0; i < tickets.size(); i++) {
		ticket[i][0] = tickets[i][0];
		ticket[i][1] = tickets[i][1];
	}
	dfs(0, tickets.size());

	return answer;
}
int  main() {
	solution({ {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"} });
	return 0;
}