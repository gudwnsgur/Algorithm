#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	vector<vector<int>> v;
	v = vector<vector<int>>(n+1, vector<int>(n+1));

	int x = 1, y = 1, length = n, s= 1;
	while (length >= 0) {
		for (int i = 0; i < length; i++)  v[x++][y] = s++;
		x--;
		for (int i = 0; i < length - 1; i++) v[x][++y] = s++;
		for (int i = 0; i < length - 2; i++) v[--x][--y] = s++;
		length -= 3;
		x++;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!v[i][j]) break;
			answer.push_back(v[i][j]);
		}
	}
	return answer;
}