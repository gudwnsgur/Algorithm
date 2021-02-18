#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define endl '\n'
using namespace std;

int n;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
string str;

vector<vector<char>> map;
vector<vector<bool>> visited;
queue<pair<char, pair<int, int>>> q;

int bfs() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				res++;
				visited[i][j] = true;
				q.push({ map[i][j],{ i, j } });
				
				while (!q.empty()) {
					for (int k = 0; k < 4; k++) {
						int nx = q.front().second.first + dx[k];
						int ny = q.front().second.second + dy[k];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n);
						else {
							if (!visited[nx][ny] && map[nx][ny] == q.front().first) {
								visited[nx][ny] = true;
								q.push({ map[nx][ny], {nx, ny} });
							}

