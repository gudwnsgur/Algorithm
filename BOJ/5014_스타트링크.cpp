#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

// F층 건물에 G층:스타트링크, 현재 강호 : S층, U:위로U층 D:아래로D층
int f, s, g, u, d;
int cnt=0;
bool visited[1000001] = { false, };

bool bfs() {
	queue<int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			if (q.front() == g) return true;
			if (q.front() + u <= f && !visited[q.front()+u]) {
				q.push(q.front() + u);
				visited[q.front() + u] = true;
			}
			if (q.front() - d >= 1 && !visited[q.front() - d]) {
				q.push(q.front() - d);
				visited[q.front() - d] = true;
			}
			q.pop();
		}
		cnt++;
	}
	return false;
}

int main() {
	cin >> f >> s >> g >> u >> d;
	if (bfs()) cout << cnt << endl;
	else cout << "use the stairs" << endl;
	return 0;
}