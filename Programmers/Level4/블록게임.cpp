#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m = 0, answer = 0;
vector<vector<pair<int, int>>> node;
vector<vector<int>> graph;
vector<bool> possible;
vector<pair<pair<int, int>, pair<int, int>>> black;


int block[5][6][2] = { {{0,0}, {1,0}, {1,1}, {1,2}, {0,1}, {0,2}},
					   {{0,0}, {1,0}, {2,-1}, {2,0}, {0,-1}, {-1,-1}},
					   {{0,0}, {1,0}, {2,0}, {2,1}, {0,1}, {1,1}},
					   {{0,0}, {1,-2}, {1,-1}, {1,0}, {0,-2}, {0,-1}},
					   {{0,0}, {1,-1}, {1,0}, {1,1} ,{0,-1}, {0,1}} };
// 0~3 real block, 4~5 black block

void checkPossibleNode() {
	for (int i = 1; i <= m; i++) {
		if (!node[i].size()) continue;
		bool pos = false;
		int dx = node[i][0].first, dy = node[i][0].second;
		for (int j = 0; j < 5; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				if(node[i][k].first-dx == block[j][k][0] &&
				   node[i][k].second-dy == block[j][k][1] ) cnt++;
			}
			if (cnt == 4) {
				black[i] = { { dx + block[j][4][0], dy + block[j][4][1] },
				{ dx + block[j][5][0], dy + block[j][5][1] } };
				pos = true;
				break;
			}
			
		}
		if (pos) possible[i] = true;
	}
	return;
}

int solution(vector<vector<int>> board) {
	n = board.size();
	vector<int> order;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j]) {
				if (board[i][j] > m) m = board[i][j];
				if (find(order.begin(), order.end(), board[i][j]) == order.end()) order.push_back(board[i][j]);
			}
		}
	}

	node = vector<vector<pair<int, int>>>(m + 1);
	possible = vector<bool>(m + 1, false);
	graph = vector<vector<int>>(m + 1);
	black = vector<pair<pair<int, int>, pair<int, int>>>(m + 1, { {-1,-1},{-1,-1} });

	for (int i = 1; i <= m; i++) graph[i].push_back(i);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j]) node[board[i][j]].push_back({ i,j });
		}
	}


	for (int i = 0; i < n; i++) {
		int j = n - 1;
		while (j >= 0 && !board[j][i]) j--;
		if (j == -1) continue;
		vector<int> line;
		line.push_back(board[j][i]);

		for (; j >= 0; j--) {
			if (board[j][i] && board[j][i] != line.back()) line.push_back(board[j][i]);
		}
		for (int j = 0; j < line.size() - 1; j++) {
			for (int k = j + 1; k < line.size(); k++) {
				graph[line[j]].push_back(line[k]);
			}
		}
	}
	checkPossibleNode();

	for (int i = 1; i <= m; i++) {
		if (graph[i].size() == 1) continue;
		for (int j = 1; j < graph[i].size(); j++) {
			for (int k = 1; k < graph[graph[i][j]].size(); k++) {
				graph[i].push_back(graph[graph[i][j]][k]);
			}
		}
	}
	for (int i = 0; i < order.size(); i++) {
		bool isPoss = true;
		int cnt = 0;
		for (int j = 0; j < graph[order[i]].size(); j++)
		{
			if (!possible[graph[order[i]][j]]) {
				isPoss = false;
			}
			if (!isPoss && order[i] == graph[order[i]][j]);
			else if (black[order[i]].first.first == -1);
			else if (!isPoss) {
				int cur = graph[order[i]][j], locCnt = 0;

				bool locBool = true;
				for (int k = 0; k < 4; k++) {
					if ((node[cur][k].first <= black[order[i]].first.first) &&
						(node[cur][k].second == black[order[i]].first.second)) {
						locBool = false;
						break;
					}
					if ((node[cur][k].first <= black[order[i]].second.first) &&
						(node[cur][k].second == black[order[i]].second.second)) {
						locBool = false;
						break;
					}
				}

				if (locBool) {
					isPoss = true;
				}
			}
			if (isPoss) cnt++;
		}
		if (cnt == graph[order[i]].size()) {
			answer++;
		}
		else {
			possible[order[i]] = false;
		}
	}
	return answer;
}
int main() {
	vector<vector<int>> boards = { {0,2,0,0}, {1,2,0,4}, {1,2,2,4}, {1,1,4,4} };
	cout << solution(boards);
	return 0;
}