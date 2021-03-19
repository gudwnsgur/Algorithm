#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> answer;
vector<vector<vector<bool>>> map;
vector<vector<int>> built, erased;

// 0, 1 : 기둥, 2, 3 보
// 0 : U, 1 : D, 2 : R , 3 : L

bool possibleBuild(int x, int y, int a) {
	if (a == 0) { // 기둥
		if (x == N) return true;	// 바닥에 기둥 설치
		if (map[1][x][y]) return true;	// 기둥 위에 기둥 설치
		if (map[2][x][y] || map[3][x][y]) return true;	// 보 위에 기둥 설치
	}
	else { // 보
		if (map[3][x][y] && map[2][x][y+1]) return true; // 보 사이에 보 설치
		if (map[1][x][y] || map[1][x][y + 1]) return true; // 기둥 위에 보 설치
	}
	return false;
}

bool possibleErase(int x, int y, int a) {
	if (a == 0) { // 기둥
		if (!map[0][x - 1][y] && !map[2][x - 1][y] && 
			!map[3][x - 1][y]) return true; // 기둥 위에 아무것도 없음

		if (map[0][x - 1][y] && !map[2][x - 1][y] && !map[3][x - 1][y]) return false;
		// 기둥 위의 기둥을 받쳐주는 보가 없을 때
		
		if (map[2][x - 1][y] && !map[1][x - 1][y + 1] && !map[2][x - 1][y + 1]) return false;
		// 기둥 오른쪽의 보를 받쳐주는 보나 기둥이 없을 때

		if (map[3][x - 1][y] && !map[1][x - 1][y - 1] && !map[3][x - 1][y - 1]) return false;
		// 기둥 왼쪽의 보를 받쳐주는 보나 기둥이 없을 때

		return true;
	}
	else {
		if (map[0][x][y] && !map[3][x][y] && !map[1][x][y]) return false;
		if (map[0][x][y+1] && !map[2][x][y+1] && !map[1][x][y+1]) return false;
		if (map[3][x][y] && !map[1][x][y] && !map[1][x][y-1]) return false;
		if (map[2][x][y+1] && !map[1][x][y+1] && !map[1][x][y+2]) return false;
	}
	return true;

}

void build(int x, int y, int a, int b) {
	cout << x << ',' << y << " 에 " << (a ? "보" : "기둥") << " : " << (b ? "건설" : "삭제") << endl;

	if (b == 0 && !possibleErase(x, y, a)) return;
	if (b == 1 && !possibleBuild(x, y, a)) return;
	vector<int> tmp(3);

	cout << "가능" << endl;
	b ? (built.push_back({ y, N - x, a })) : (erased.push_back({ y, N - x, a }));

	if (a == 0) { // 기둥
		if (b == 1) map[0][x][y] = map[1][x - 1][y] = true;  // 건설
		else map[0][x][y] = map[1][x - 1][y] = false; // 삭제
	}
	else {	// 보
		if (b == 1) map[2][x][y] = map[3][x][y + 1] = true; // 건설
		else map[2][x][y] = map[3][x][y + 1] = false; // 삭제
	}
}
bool compare (vector<int> a, vector<int> b) {
	if (a[0] == b[0]) {
		if (a[1] == b[1]) return a[2] < b[2];
		return a[1] < b[1];
	}
	return a[0] < b[0];
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	N = n;
	map = vector<vector<vector<bool>>>(4, vector<vector<bool>>(n + 2, vector<bool>(n + 2, false)));

	for (int i = 0; i < build_frame.size(); i++) {
		build(n - build_frame[i][1], build_frame[i][0], build_frame[i][2], build_frame[i][3]);
	}
	for (int i = 0; i < built.size(); i++) {
		cout << built[i][0] << ',' << built[i][1] << " : " << built[i][2] << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < erased.size(); i++) {
		cout << erased[i][0] << ',' << erased[i][1] << " : " << erased[i][2] << endl;
	}
	
	for (int i = 0; i < built.size(); i++) {
		bool pos = true;
		for (int j = 0; j < erased.size(); j++) {
			if (built[i][0] == erased[j][0] && 
				built[i][1] == erased[j][1] && built[i][2] == erased[j][2]) {
				pos = false;
				break;
			}
		}
		if (pos) answer.push_back(built[i]);
	}

	cout << "답 " << endl;
	sort(answer.begin(), answer.end(), compare);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i][0] << ' ' << answer[i][1] << ' ' << answer[i][2] << endl;
	}
	return answer;
}
