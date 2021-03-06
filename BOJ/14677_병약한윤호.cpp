// BFS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define endl '\n'
using namespace std;

struct info {
	int left, right;
	int cnt;
	int next;
};

int n, res = 0;
char order[3] = { 'B', 'L', 'D' };
string drug;
queue<info> q;
vector<vector<bool>> visited;


int main() {
	cin >> n;
	cin >> drug;
	visited = vector<vector<bool>>(drug.size()+1, vector<bool>(drug.size()+1, false));

	if (drug[0] == 'B') {
		q.push({ 1, (int)drug.size() - 1, 1, 0 });
		visited[1][drug.size() - 1] = true;
	}
	if (drug[drug.size() - 1] == 'B') {
		visited[0][drug.size() - 2] = true;
		q.push({ 0, (int)drug.size() - 2, 1, 0 });
	}


	while (!q.empty()) {
		res = max(res, q.front().cnt);
		int curL = q.front().left, curR = q.front().right;
		int curCnt = q.front().cnt, curN = q.front().next;

		cout << curL << ' ' << curR << ' ' << curCnt << ' ' << order[curN] << endl;

		if (curL >= 0 && curR < drug.size() && curL <= curR) {
			if (drug[curL] == order[(curN + 1) % 3] && !visited[curL + 1][curR]) {
				q.push({ curL + 1, curR, curCnt + 1, (curN + 1) % 3 });
			}
			if (drug[curR] == order[(curN + 1) % 3] && !visited[curL][curR - 1]) {
				q.push({ curL, curR - 1, curCnt + 1, (curN + 1) % 3 });
			}
		}
		q.pop();
	}

	cout << res << endl;
	return 0;
}


// DFS ( 재귀)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

int n, res = 0;
char order[3] = { 'B', 'L', 'D' };
string drug;
vector<vector<bool>> visited;

void recursive(int left, int right, int cnt, int next) {
	res = max(cnt, res);

	if (left >= drug.size() || right < 0 || left > right) {
		res = max(cnt, res);
		return;
	}

	if (drug[left] == order[next] && !visited[left + 1][right]) {
		visited[left + 1][right] = true;
		recursive(left + 1, right, cnt + 1, (next + 1) % 3);
	}
	if (drug[right] == order[next] && !visited[left][right-1]  ) {
		visited[left][right-1] = true;
		recursive(left, right - 1, cnt + 1, (next + 1) % 3);
	}
}

int main() {
	cin >> n;
	cin >> drug;
	visited = vector<vector<bool>>(drug.size() + 1, vector<bool>(drug.size() + 1, false));

	if (drug[0] == 'B') {
		visited[1][drug.size() - 1] = true;
		recursive(1, drug.size() - 1, 1, 1);
	}

	if (drug[drug.size() - 1] == 'B') {
		visited[0][drug.size() - 2] = true;
		recursive(0, drug.size() - 2, 1, 1);

	}
	cout << res << endl;
	return 0;
}
