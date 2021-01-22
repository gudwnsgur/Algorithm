#include <string>
#include <vector>
#include <iostream>
using namespace std;

int cnt[2] = { 0, 0 };
vector<vector<int>> map;

void recursion(int n, int x, int y) {
	if (n < 1) return;

	int start = map[x][y];
	bool same = true;
	for (int i = x; i < n+x; i++) {
		if (!same) break;
		for (int j = y; j < n+y; j++) {
			if (start != map[i][j]) {
				same = false;
				break;
			}
		}
	}

	if (same) {
		cnt[start]++;
		return;
	}
	n /= 2;
	recursion(n, x, y);
	recursion(n, x + n, y);
	recursion(n, x, y + n);
	recursion(n, x + n, y + n);
}

vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer;
	map = arr;
	int n = arr.size();

	recursion(n, 0, 0);
	answer.push_back(cnt[0]);
	answer.push_back(cnt[1]);
	return answer;
}
