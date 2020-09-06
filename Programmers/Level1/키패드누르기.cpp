#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int middle[4][12] = {{3, 1, 0, 1, 2, 1, 2, 3, 2, 3, 4, 4},  // 2
					 {2, 2, 1, 2, 1, 0, 1, 2, 1, 2, 3, 3},  // 5
					 {1, 3, 2, 3, 2, 1, 2, 1, 0, 1, 2, 2},  // 8
					 {0, 4, 3, 4, 3, 2, 3, 2, 1, 2, 1, 1} };// 0

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int L = 10, R = 11;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			L = numbers[i];		answer += "L";
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			R = numbers[i];		answer += "R";
		}
		else {
			int n = numbers[i];
			n = (n == 2 ? 0 : (n == 5 ? 1 : (n == 8 ? 2 : 3)));

			if ((middle[n][L] == middle[n][R] && hand == "left") ||
				middle[n][L] < middle[n][R]) {
				L = numbers[i];		answer += "L";
			}
			else {
				R = numbers[i];		answer += "R";
			}
		}
	}
	return answer;
}