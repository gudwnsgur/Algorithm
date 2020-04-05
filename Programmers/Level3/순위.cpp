#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool winTable[101][101]{ false, };
bool loseTable[101][101]{ false, };

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	for (int i = 0; i < results.size(); i++) {
		winTable[results[i][0]][results[i][1]] = true;
		loseTable[results[i][1]][results[i][0]] = true;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (winTable[j][i] && winTable[i][k]) {
					winTable[j][k] = true;
				}
				if (loseTable[j][i] && loseTable[i][k]) {
					loseTable[j][k] = true;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (winTable[i][j] || loseTable[i][j]) cnt++;
		}
		if (cnt == n - 1) answer++;
	}
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << winTable[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << loseTable[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	return answer;
}

// testCase 
int main() {
	int n = 8;
	vector<vector<int>> v = { {1,2},{2,3},{3,4},{5,6},{3,7},{3,6},{7,8} };
	cout << solution(n, v);
	return 0;
}