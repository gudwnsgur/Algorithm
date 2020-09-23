#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define X first
#define Y second
using namespace std;

bool visited[101][101][4] = { false, }; 
// R, D, L, U

int solution(vector<vector<int>> board) {
	int n = board.size();
	int answer = 0;
	queue<pair<pair<int,int>, pair<int,int>>> q; // 뒷바퀴 + 앞바퀴
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	visited[0][0][0] = true;
	visited[0][1][2] = true;

	while (!q.empty()) {
		int size = q.size();
		cout << answer << endl;
		for (int i = 0; i < size; i++) {
			int bx =q.front().X.X, by = q.front().X.Y, fx = q.front().Y.X, fy = q.front().Y.Y;
			
			cout << "(" << bx << ", " << by << ") -> " << "(" << fx << ", " << fy << ")" << endl;

			if ((bx == n - 1 && by == n - 1) || (fx == n - 1 && fy == n - 1)) return answer;

			if (by == fy) {
				/* by
				fy */
				if (by != 0 && fy != 0 && !board[bx][by - 1] && !board[fx][fy - 1] && !visited[bx][by-1][1]) {
					q.push(make_pair(make_pair(bx, by-1), make_pair(fx, fy-1)));
					visited[bx][by-1][1] = true;
					visited[fx][fy-1][3] = true;
				}
				if (by != n-1 && fy != n-1 && !board[bx][by + 1] && !board[fx][fy + 1] && !visited[bx][by + 1][1]) {
					q.push(make_pair(make_pair(bx, by + 1), make_pair(fx, fy + 1)));
					visited[bx][by + 1][1] = true;
					visited[fx][fy + 1][3] = true;
				}
				if (bx != 0 && !board[bx - 1][by] && !visited[bx][by][3]) {
					q.push(make_pair(make_pair(bx - 1, by), make_pair(fx - 1, fy)));
					visited[bx][by][3] = true;
					visited[bx - 1][by][1] = true;
				}
				if (fx != n - 1 && !board[fx + 1][fy] && !visited[fx][fy][1]) {
					q.push(make_pair(make_pair(bx + 1, by), make_pair(fx + 1, fy)));
					visited[fx][fy][1] = true;
					visited[fx + 1][fy][3] = true;
				}
				if (by != n - 1 && fy != n - 1 && !board[bx][by + 1] && !board[fx][fy + 1]) {
					if (!visited[bx][by][0]) {
						q.push(make_pair(make_pair(bx, by), make_pair(fx - 1, fy+1)));
						visited[bx][by][0] = true;
						visited[bx][by+1][2] = true;
					}
					if (!visited[fx][fy][0]) {
						q.push(make_pair(make_pair(fx, fy), make_pair(bx+1, by+1)));
						visited[fx][fy][0] = true;
						visited[fx][fy + 1][2] = true;
					}
				}
				if (by != 0 && fy != 0 && !board[bx][by - 1] && !board[fx][fy - 1]) {
					if (!visited[bx][by][2]) {
						q.push(make_pair(make_pair(fx-1, fy-1), make_pair(bx, by)));
						visited[bx][by][2] = true;
						visited[bx][by - 1][0] = true;
					}
					if (!visited[fx][fy][2]) {
						q.push(make_pair(make_pair(bx+1, by - 1), make_pair(fx, fy)));
						visited[fx][fy][2] = true;
						visited[fx][fy - 1][0] = true;
					}
				}
			}
			else {

				// by -> fy
				if (bx != 0 && fx != 0 && !board[bx - 1][by] && !board[fx - 1][fy] && !visited[bx-1][by][0]) {
					q.push(make_pair(make_pair(bx - 1, by), make_pair(fx - 1, fy)));
					visited[bx-1][by][0] = true;
					visited[fx-1][fy][2] = true;
				}
				if (bx != n - 1 && fx != n - 1 && !board[bx + 1][by] && !board[fx + 1][fy] && !visited[bx+1][by][0]) {
					q.push(make_pair(make_pair(bx + 1, by), make_pair(fx + 1, fy)));
					visited[bx + 1][by][0] = true;
					visited[fx + 1][fy][2] = true;
				}

				if (by != 0 && !board[bx][by - 1] && !visited[bx][by][2]) {
					q.push(make_pair(make_pair(bx, by - 1), make_pair(fx, fy - 1)));
					visited[bx][by][2] = true;
					visited[bx][by - 1][0] = true;
				}
				if (fy != n-1 && !board[fx][fy + 1] && !visited[fx][fy][0]) {
					q.push(make_pair(make_pair(bx, by + 1), make_pair(fx, fy + 1)));
					visited[fx][fy][0] = true;
					visited[fx][fy + 1][2] = true;
				}
				if (bx != n - 1 && fx != n - 1 && !board[bx + 1][by] && !board[fx + 1][fy]) {
					if (!visited[bx][by][1]) {
						q.push(make_pair(make_pair(bx, by), make_pair(fx+1, fy-1)));
						visited[bx][by][1] = true;
						visited[bx+1][by][3] = true;
					}
					if (!visited[fx][fy][1]) {
						q.push(make_pair(make_pair(fx, fy), make_pair(bx+1, by+1)));
						visited[fx][fy][1] = true;
						visited[fx + 1][fy][3] = true;
					}
				}
				if (bx != 0 && fx != 0 && !board[bx - 1][by] && !board[fx - 1][fy]) {
					if (!visited[bx][by][3]) {
						q.push(make_pair(make_pair(fx-1,fy-1), make_pair(bx,by)));
						visited[bx][by][3] = true;
						visited[bx-1][by][1] = true;
					}
					if (!visited[fx][fy][3]) {
						q.push(make_pair(make_pair(bx-1, by+1), make_pair(fx, fy)));
						visited[fx][fy][3] = true;
						visited[fx-1][fy][1] = true;
					}
				}
			}
			q.pop();
		}
		answer++;
	}
	return answer;
}