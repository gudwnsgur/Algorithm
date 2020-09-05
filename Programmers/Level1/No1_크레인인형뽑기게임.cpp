#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int std[31] = { 0, };
	for (int i = 0; i < lost.size(); i++) std[lost[i]]--;
	for (int i = 0; i < reserve.size(); i++) std[reserve[i]]++;

	for (int i = 1; i <= n; i++) {
		if (std[i] == -1) {
			if (std[i - 1] == 1) {
				std[i - 1] = std[i] = 0;
			}
			else if (std[i + 1] == 1) {
				std[i]  = std[i+1] = 0;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (std[i] != -1) answer++;
	}
	return answer;
}