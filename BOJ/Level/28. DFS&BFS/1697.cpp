#include <iostream>
#include <queue>
using namespace std;
#define MAX 100000
int result = 0;
bool visited[MAX+1]{ false, };

void bfs(int n, int k) {
	queue<int> q;
	q.push(n);
	visited[n] = true;

	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int number = q.front();
			if (number == k) {
				cout <<  result ;
				return;
			}
			if (number * 2 <= MAX && !visited[number * 2]) {
				q.push(number * 2);
				visited[number * 2] = true;
			}
			if (!visited[number + 1] && number+1<=MAX) { 
				q.push(number + 1); 
				visited[number + 1] = true;
			}
			if (!visited[number - 1] && number-1>=0) {
				q.push(number - 1);
				visited[number - 1] = true;
			}
			q.pop();
		}
		result++;
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	bfs(n, k);
	return 0;
}
