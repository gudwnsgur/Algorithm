#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int bfs(int x, int y, int m, int n, bool visited[101][101], int map[101][101]) {
	queue<pair<int, int>> q;
	int area=1, color = map[x][y];
	visited[x][y] = true;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int a = q.front().first;
			int b = q.front().second;

			if (a != 0 && map[a - 1][b] == color && !visited[a - 1][b]) {
				q.push(make_pair(a - 1, b));
				visited[a - 1][b] = true;
				area++;
			}
			if (a != m && map[a+1][b] == color && !visited[a + 1][b]) {
				q.push(make_pair(a + 1, b));
				visited[a + 1][b] = true;
				area++;
			}if (b != 0 && map[a][b-1] == color && !visited[a][b-1]) {
				q.push(make_pair(a, b-1));
				visited[a][b-1] = true;
				area++;
			}if (b != n && map[a][b+1] == color && !visited[a][b+1]) {
				q.push(make_pair(a , b+1));
				visited[a][b+1] = true;
				area++;
			}
			q.pop();
		}
	}

	return area;
}


vector<int> solution(int m, int n, vector<vector<int>> picture) 
{
	bool visited[101][101]{ false, };
	int map[101][101]{ 0, };
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = picture[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j]) {
				number_of_area++;
				max_size_of_one_area = max(max_size_of_one_area, bfs(i,j,m,n, visited, map));
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	vector<int> a = solution(6, 4, {
		{1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} });
	cout << a[0] << ' ' << a[1] << endl;
	return 0;
}
