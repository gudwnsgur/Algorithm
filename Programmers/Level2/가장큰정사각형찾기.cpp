#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int solution(vector<vector<int>> board)
{
	n = board.size();
	m = board[0].size();
	if (n == 0 || m == 0) return 0;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j]) cnt++;
		}
	}
	if (!cnt) return 0;

	int maxNum = 1;
	for (int i = 1; i <n; i++) {
		for (int j = 1; j < m; j++) {
			if (board[i][j] && board[i - 1][j - 1] && board[i][j - 1] && board[i - 1][j]) {
				board[i][j] = min(board[i - 1][j - 1], min(board[i][j - 1], board[i - 1][j])) + 1;
				maxNum = max(maxNum, board[i][j]);
			}
		}
	}
	return maxNum*maxNum;
}


int main() {
	vector<vector<int>> v;
	vector<int> a = { 0, 1,1,1};
	vector<int> b = { 1,1,1,1 };
	vector<int> c = { 1,1,1,1 };
	vector<int> d = { 0,0,1,0 };
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	cout << solution(v);
	return 0;
}