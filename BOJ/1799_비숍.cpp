#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int n, result1, result2;
bool ended = false;
int board[10][10] = { 0, };
vector<pair<int, int>> white;
vector<pair<int, int>> black;
vector<pair<int, int>> check(101);
bool visited[10][10] = { false, };

bool promising(int x, int y) {
	// check 배열에 들어간 index들에 비숍이 위치할 수 있는지 판단
	for (int i = 1; i < n; i++) {
		if (x + i < n) {
			if (y + i < n) if (visited[x + i][y + i]) return false;
			if (y - i >= 0) if (visited[x + i][y - i]) return false;
		}
		if (x - i >= 0) {
			if (y + i < n) if (visited[x - i][y + i]) return false;
			if (y - i >= 0) if (visited[x - i][y - i]) return false;
		}

	}
	return true;
}


void whiteDfs(int length, int m) {
	// v.size() C m 의 경우의 수 
	if (!ended) {
		if (length == m) {
			result1 = m;
			ended = true;
			return;
		}
		for (int i = 0; i < white.size(); i++) {
			if (!visited[white[i].X][white[i].Y] && promising(white[i].X, white[i].Y)) {
				if (length == 0 || (length > 0 && check[length - 1].X * 10 + check[length - 1].Y < white[i].X * 10 + white[i].Y)) {
					check[length].X = white[i].X; check[length].Y = white[i].Y;


					visited[white[i].X][white[i].Y] = true;
					whiteDfs(length + 1, m);
					visited[white[i].X][white[i].Y] = false;
				}
			}
		}
	}
}
void blackDfs(int length, int m) {
	// v.size() C m 의 경우의 수 
	if (!ended) {
		if (length == m) {
			result2 = m;
			ended = true;
			return;
		}
		for (int i = 0; i < black.size(); i++) {
			if (!visited[black[i].X][black[i].Y] && promising(black[i].X, black[i].Y)) {
				if (length == 0 || (length > 0 && check[length - 1].X * 10 + check[length - 1].Y < black[i].X * 10 + black[i].Y)) {
					check[length].X = black[i].X; check[length].Y = black[i].Y;


					visited[black[i].X][black[i].Y] = true;
					blackDfs(length + 1, m);
					visited[black[i].X][black[i].Y] = false;
				}
			}
		}
	}
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				if(i%2== j%2) white.push_back(make_pair(i, j));
				else black.push_back(make_pair(i, j));
			}
		}
	}

	// 비숍은 최대 min(2n-2 , 칸 1 의 개수) 만큼 존재할 수 있다.
	for (int i = min(2 * n - 2, (int)white.size()); i >= 0; i--)
	{
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				visited[j][k] = false;
			}
		} // visted 초기화

		whiteDfs(0, i); // i개를 고를 경우의 수
	}


	ended = false;

	for (int i = min(2 * n - 2, (int)black.size()); i >= 0; i--)
	{
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				visited[j][k] = false;
			}
		} // visted 초기화

		blackDfs(0, i); // i개를 고를 경우의 수
	}

	cout << result1 + result2 << endl;
	return 0;
}