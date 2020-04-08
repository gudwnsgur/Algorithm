#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001

int tomato[MAX][MAX]{ 0, };
int day = -1;
queue<pair<int, int>> curQ;
queue<pair<int, int>> nextQ;


void bfs(int n, int m) 
{
	while (!curQ.empty()) 
	{
		day++;
		//cout << day << " 일 차 " << endl;
		while (!curQ.empty()) {
			nextQ.push(curQ.front());
			// cout << "검사 할 노드 : " << curQ.front().first << ' ' << curQ.front().second << endl;
			curQ.pop();
		}
		while (!nextQ.empty()) {
			int i = nextQ.front().first;
			int j = nextQ.front().second;
		
			if (i != n && tomato[i + 1][j] == 0) {
				tomato[i + 1][j] = 1;
				curQ.push(make_pair(i + 1, j));
				// cout << "검사 된 노드 : " << i+1 << ' ' <<  j << endl;
			}
			if (j != m && tomato[i][j+1] == 0) {
				tomato[i][j+1] = 1;
				curQ.push(make_pair(i, j+1));
				// cout << "검사 된 노드 : " << i << ' ' << j+1 << endl;

			}
			if (i != 0 && tomato[i-1][j] == 0) {
				tomato[i-1][j] = 1;
				curQ.push(make_pair(i-1, j));
				// cout << "검사 된 노드 : " << i -1 << ' ' << j << endl;

			}
			if (j != 0 && tomato[i][j-1] == 0) {
				tomato[i][j-1] = 1;
				curQ.push(make_pair(i, j-1));
				// cout << "검사 된 노드 : " << i  << ' ' << j -1<< endl;
			}
			nextQ.pop();
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (tomato[i][j] == 0) {
				day = -1;
				return;
			}
		}
	}
}

int main() {
	int n, m;

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				curQ.push(make_pair(i, j));
			}
		}
	}

	bfs(n-1, m-1);
	cout << day;
	return 0;
}