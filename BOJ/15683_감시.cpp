#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define endl '\n'
#define X first
#define Y second
using namespace std;

int cnt = 0;
int maxValidateArea = 0, result = 0;
int office[10][10];
vector<pair<pair<int, int>, int>> v;
int cctv[9]; // 1, 2, 3, 4
int n, m;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> office[i][j];
			if (office[i][j] >= 1 && office[i][j] <= 5)
				v.push_back(make_pair(make_pair(i, j), office[i][j]));
			if (!office[i][j]) result++; // 빈방(0)
		}
	}
}
int cntValidateArea() {

	// cctv 개수 v.szie() / cctv 방향 cctv[] / 방 office[][]
	int area = 0;

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].X.X, y = v[i].X.Y;

		// Right
		if ((v[i].Y == 1 && cctv[i] == 1) ||  // 1
			(v[i].Y == 2 && cctv[i] == 1) || // 2
			(v[i].Y == 3 && (cctv[i] == 1 || cctv[i] == 2)) ||	// 3
			(v[i].Y == 4 && cctv[i] != 4) ||	// 4
			(v[i].Y == 5))	// 5
		{
			for (int j = y+1 ; j < m && office[x][j] != 6; j++) 
				if (office[x][j] == 0) office[x][j] = -1;
		}


		// Down
		if ((v[i].Y == 1 && cctv[i] == 2) ||  // 1
			(v[i].Y == 2 && cctv[i] == 2) || // 2
			(v[i].Y == 3 && (cctv[i] == 2 || cctv[i] == 3)) ||	// 3
			(v[i].Y == 4 && cctv[i] != 1) ||	// 4
			(v[i].Y == 5)
			)	// 5
		{
			for (int j = x+1 ; j < n && office[j][y] != 6; j++) 
				if (office[j][y] == 0) office[j][y] = -1;
		}


		// Left
		if ((v[i].Y == 1 && cctv[i] == 3) ||  // 1
			(v[i].Y == 2 && cctv[i] == 1) || // 2
			(v[i].Y == 3 && (cctv[i] == 3 || cctv[i] == 4)) ||	// 3
			(v[i].Y == 4 && cctv[i] != 2) ||	// 4
			(v[i].Y == 5))	// 5
		{
			for (int j = y-1; j >= 0 && office[x][j] != 6; j--) 
				if (office[x][j] == 0) office[x][j] = -1;
		}

		// Up
		if ((v[i].Y == 1 && cctv[i] == 4) ||  // 1
			(v[i].Y == 2 && cctv[i] == 2) || // 2
			(v[i].Y == 3 && (cctv[i] == 4 || cctv[i] == 1)) ||	// 3
			(v[i].Y == 4 && cctv[i] != 3) ||	// 4
			(v[i].Y == 5))	// 5
		{
			for (int j = x-1; j >= 0 && office[j][y] != 6; j--) 
				if (office[j][y] == 0) office[j][y] = -1;
		}



	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (office[i][j] == -1) {
				area++;
				office[i][j] = 0;
			}
		}
	}
	return area;
}

void dfs(int length) {
	if (length == v.size()) {
		maxValidateArea = max(maxValidateArea, cntValidateArea());
		return;
	}
	for (int i = 1; i <= 4; i++) {
		if (v[length].Y == 2 && (i == 3 || i == 4)); // 두가지 경우
		else if (v[length].Y == 5 && i != 1); // 한가지 경우
		else {
			cctv[length] = i;
			dfs(length + 1);
		}
	}
}


int main() {

	input();
	dfs(0);

	cout << result - maxValidateArea << endl; // 빈방 - 가릴 수 있는 방의 최대
	return 0;
}