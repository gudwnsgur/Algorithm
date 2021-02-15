#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> arr[3][2][2][2];
vector<int> answer;

int solve(string q) {
	vector<int> curScore;
	int score, res =0;
	int curInfo[4];

	for (int i = 0; i < q.size(); i++) {
		int idx = 0;

		if (q[0] == '-') curInfo[0] = 3;
		else curInfo[0] = q[0] == 'c' ? 0 : (q[0] == 'j' ? 1 : 2);
		idx++;

		while (q[idx] != 'b' && q[idx] != 'f' && q[idx] != '-') idx++;
		curInfo[1] = q[idx] == 'f' ? 0 : (q[idx] == 'b' ? 1 : 2);
		idx++;

		while (q[idx] != 'j' && q[idx] != 's' && q[idx] != '-') idx++;
		curInfo[2] = q[idx] == 'j' ? 0 : (q[idx] == 's' ? 1 : 2);
		idx++;

		while (q[idx] != 'p' && q[idx] != 'c' && q[idx] != '-') idx++;
		curInfo[3] = q[idx] == 'p' ? 0 : (q[idx] == 'c' ? 1 : 2);


		while (q[idx] < '0' || q[idx] > '9') idx++;
		score = stoi(q.substr(idx, q.size() - idx));
	}
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 2; b++) {
			for (int c = 0; c < 2; c++) {
				for (int d = 0; d < 2; d++) {
					if (curInfo[0] != 3 && curInfo[0] != a);
					else if (curInfo[1] != 2 && curInfo[1] != b);
					else if (curInfo[2] != 2 && curInfo[2] != c);
					else if (curInfo[3] != 2 && curInfo[3] != d);
					else {
						for (int i = 0; i < arr[a][b][c][d].size(); i++) curScore.push_back(arr[a][b][c][d][i]);
					}
				}
			}
		}
	}
	for (int i = 0; i < curScore.size(); i++) if (curScore[i] >= score) res++;
	return res;
}

vector<int> solution(vector<string> info, vector<string> query) {
	for (int i = 0; i < info.size(); i++) {
		int curInfo[4];
		int idx = 0;
		curInfo[0] = info[i][0] == 'c' ? 0 : (info[i][0] == 'j' ? 1 : 2);

		while (info[i][idx] != 'b' && info[i][idx] != 'f') idx++;
		curInfo[1] = info[i][idx] == 'f' ? 0 : 1;

		while (info[i][idx] != 'j' && info[i][idx] != 's') idx++;
		curInfo[2] = info[i][idx] == 'j' ? 0 : 1;

