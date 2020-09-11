#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool visited[51] = { false, };
int n, cnt = 1;
int solution(string begin, string target, vector<string> words) {
	n = words.size(); // n = 6

	queue<string> q;
	q.push(begin);
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i <qSize; i++) {
			string cur = q.front();
			for (int j = 0; j < n; j++) {
				int diff = 0;
				if (!visited[j]) {
					for (int k = 0; k < cur.size(); k++)  {
						if (cur[k] != words[j][k]) diff++;
					}
					if (diff == 1) {
						if (!words[j].compare(target)) return cnt;
						visited[j] = true;
						q.push(words[j]);
					}
				}
			}
			q.pop();
		}
		cnt++;
	}
	return 0;
}
int main() {
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });
	return 0;
}