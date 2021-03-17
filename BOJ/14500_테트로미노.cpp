#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define endl '\n'
#define X first
#define Y second
using namespace std;

int n, m, result = 0;
int tetris[19][4][2] = { {{0, 0}, {1, 0}, {0,1}, {1, 1}},
								{{0, 0}, {0, 1}, {0, 2}, {0,3 }},

								{{0,0}, {1,0}, {2, 0}, {3,0}},

								{{0,0}, {1,0}, {2, 0}, {2,1}},
								{{0, 1}, {1, 1}, {2, 1}, {2,0}},
								{{0,0}, {0,1}, {0,2} , {1,2}},
								{{0,0}, {0, 1} ,{1, 0}, {2, 0}},
								{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
								{{0,0}, {1,0}, {0,1}, {0, 2}},
								{{0,0}, {1,0}, {1,1 }, {1, 2}},
								{{1,0}, {1,1}, {1,2}, {0,2}},

								{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
								{{0,1}, {1, 1}, {1, 0}, {2,0}},
								{{0, 0}, {0, 1}, {1, 1}, {1, 2}},
								{{1,0}, {1, 1}, {0, 1} , {0, 2}},

								{{0, 0}, {0,1 } , {0,2 } ,{1,1 }},
								{{0,0}, {1, 0}, {2, 0}, {1,1 }},
								{{1, 0}, {1, 1} ,{1,2} , {0,1}},
								{{0,1 }, {1, 1}, {2, 1}, {1, 0}}
								};
vector<vector<int>> map;


void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			// i, j : 중점
			pair<int, int> cur[4];
			for (int k = 0; k < 19; k++) {
				int curCnt = 0;
				bool pos = true;

				for (int l = 0; l < 4; l++) {
					cur[l].X = tetris[k][l][0] + i, cur[l].Y = tetris[k][l][1] + j;
					if (cur[l].X <= 0 || cur[l].X > n || cur[l].Y <= 0 || cur[l].Y > m)  pos = false;
				}

				if (!pos) continue;
				for (int l = 0; l < 4; l++) curCnt += map[cur[l].X][cur[l].Y];
				result = max(result, curCnt);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> n >> m;
	map = vector<vector<int>>(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << result << endl;
	return 0;
}
