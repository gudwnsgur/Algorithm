#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

bool map[26][26]{ false, };	 
bool visited[26][26] { false , }; 
vector<int> DDANZI;	// 단.지.


void dfs(int i, int j, int n) {
	visited[i][j] = true;	// map[i][j] 방문
	DDANZI.back()++; // 해당 단지에 집 추가

	if (i != 0 && !visited[i-1][j] && map[i-1][j])	dfs(i - 1, j, n);
	if (j != 0 && !visited[i][j-1] && map[i][j-1]) dfs(i, j - 1, n);
	if (i != n - 1 && !visited[i+1][j] && map[i+1][j]) dfs(i + 1, j, n);
	if (j != n - 1 && !visited[i][j+1] && map[i][j+1]) dfs(i, j + 1, n);
	// 상, 좌, 하, 우 순서로 판별
	// 해당 위치에 집이 존재 && 방문하지 않았을때 dfs 
}

int main() {
	int n, answer = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < n; j++) {
			if (line[j] == '0') map[i][j] = false;
			else map[i][j] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j]) {
				DDANZI.push_back(0); // 새로운 단지 추가
				dfs(i, j, n); // 해당 단지 DFS
			}
		}
	}
	sort(DDANZI.begin(), DDANZI.end()); // 오름차순 정렬
	cout << DDANZI.size() << endl;
	for (int i = 0; i < DDANZI.size(); i++) {
		cout << DDANZI[i] << endl;
	}
	return 0;
}