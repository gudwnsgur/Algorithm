#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<pair<int, int>> house, chicken;
vector<vector<int>> map;
int minDist = 2147483647;
vector<int> arr;
vector<bool> visited;

void calculateDist() {
	int dist = 0;
	for (int i = 0; i < house.size(); i++) {
		int curDist = 2147483647;
		for (int j = 0; j < arr.size(); j++) {
			curDist = min(curDist, map[i][arr[j]]);
		}
		dist += curDist;
	}
	minDist = min(dist, minDist);
	return;
}

void dfs(int length, int n, int m) {
	if (length == m) {
		calculateDist();
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (length == 0 || (length != 0 && arr[length - 1] < i)) {
				visited[i] = true;
				arr[length] = i;
				dfs(length + 1, n, m);
				visited[i] = false;
			}
		}
	}
}

int solve(int n, int m) {
	int num;
	for (int i = 0; i < n*n; i++) {
		cin >> num;
		if (num == 1) house.push_back({ i / n, i%n });
		else if (num == 2) chicken.push_back({ i / n, i%n });
	}

	map = vector<vector<int>>(house.size(), vector<int>(chicken.size(), 0));
	/*
	for (int i = 0; i < house.size(); i++) cout << house[i].first << ' ' << house[i].second << endl;
	cout << endl;
	for (int i = 0; i < chicken.size(); i++) cout << chicken[i].first << ' ' << chicken[i].second << endl;
	cout << endl;
	*/
	for (int i = 0; i < house.size(); i++) {
		for (int j = 0; j < chicken.size(); j++) {
			int curHx = house[i].first, curHy = house[i].second,

