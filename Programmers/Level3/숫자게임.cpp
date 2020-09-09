#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	int teamA = 0, teamB = 0;

	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), greater<int>());
	if (A[A.size() - 1] >= B[0]) return 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[teamA] < B[teamB]) {
			teamB++;	
			answer++;
		}
		teamA++;
	}
	return answer;
}
int main() {
	return 0;
}