#include <string>
#include <stack>
#include <vector>
using namespace std;

int board[30][30];
stack<int> s;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	for (int i = 0; i < moves.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			int cur = board[j][moves[i] - 1];
			if (cur) {
				if(!s.empty()) {
					if (s.top() == cur) {
						s.pop();
						answer += 2;
					}
					else s.push(cur);
				}
				else s.push(cur);
				board[j][moves[i] - 1] = 0;
				break;
			}
		}
	}
	return answer;
}