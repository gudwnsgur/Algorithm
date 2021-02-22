#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<char>> map;
bool visited[26] = { false, };
int result = 1;
int r, c;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };



int main () {
	cin >> r >> c;
	
	map = vector<vector<char>>(r, vector<char>(c));

	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			map[i][j] = str[j];
		}
	}
	visited[map[0][0] - 'A'] = true;

	return 0;
}
