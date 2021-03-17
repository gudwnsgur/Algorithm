#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define endl '\n'
#define X first
#define Y second
using namespace std;

int n, apple, op, x, y;
pair<int, int> head, tail;
int dx[4] = {0, 1, 0, -1};
int dy[4] = { 1, 0, -1, 0 };

deque<pair<int, int>> snake;
vector<vector<int>> map;
vector<int> moveDir(10001, 0);


int solve() {
	int time = 0, curDir = 0;
	while (true) {
		time++;

		// 다음 대가리가 가야하는 위치
		int nx = snake.front().X + dx[curDir];
		int ny = snake.front().Y + dy[curDir];

		// 대가리가 벽에 다으면 
		if (nx <= 0 || nx > n || ny <= 0 || ny > n) return time;

		// 지 몸에 박으면
		if (map[nx][ny] == 1) return time;

		// 사과를 안먹었으면
		if (map[nx][ny] != 2) {
			map[snake.back().X][snake.back().Y] = 0;
			snake.pop_back();
		}

		// 대가리 저장
		map[nx][ny] = 1;
		snake.push_front({ nx, ny });


		// 회전
		// (time, dir(1, -1))
		curDir = (curDir + moveDir[time] + 4) % 4;

	}
	return time;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> apple;
	map = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	map[1][1] = 1; //snake
	head = tail = { 1,1 };
	snake.push_front({ 1, 1 });

	for (int i = 0; i < apple; i++) {
		cin >> x >> y;
		map[x][y] = 2; // apple
	}
	
	cin >> op;
	char ch;
	for (int i = 0; i < op; i++) {
		cin >> x >> ch;
		moveDir[x] = (ch == 'D' ? 1 : -1);
	}

	cout << solve() << endl;
	return 0;
}
