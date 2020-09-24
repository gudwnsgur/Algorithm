#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> answer;

void hanoi(int n, int from, int to, int via) {
	if (n == 1) {
		answer.push_back({from, to});
		return;
	}
	hanoi(n - 1, from, via, to);
	answer.push_back({from, to});
	hanoi(n - 1, via, to, from);
}


vector<vector<int>> solution(int n) {
	hanoi(n, 1, 3, 2);
	return answer;
}