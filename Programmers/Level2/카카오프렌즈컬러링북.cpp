#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

bool visited[101][101] = { false, };
int map[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int n, m;


int bfs(int xx, int yy) {
	int cnt = 1, num = map[xx][yy];
	queue<pair<int, int>> q;
	q.push(make_pair(xx, yy));

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first, y = q.front().second;
			for (int j = 0; j < 4; j++) 
			{
				int nx = dx[j] + x;
				int ny = dy[j] + y;
				if (nx < 0 || nx >= m || ny < 0 || ny >= n);
				
				else if (!visited[nx][ny] && map[nx][ny] == num) {
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
					cnt++;
				}
			}
			q.pop();
		}
	}
	return cnt;
}

vector<int> solution(int mm, int nn, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	m = mm; n = nn;
    
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = picture[i][j];
			visited[i][j] = false;
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j]) {
				visited[i][j] = true;
				number_of_area++;
				max_size_of_one_area = max(max_size_of_one_area, bfs(i, j));
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
		{ 1,1,1,0 },{ 1,2,2,0 },{ 1,0,0,1 },{ 0,0,0,1 },{ 0,0,0,3 },{ 0,0,0,3 } });
	cout << a[0] << ' ' << a[1] << endl;
	return 0;
}