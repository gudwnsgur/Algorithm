#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;


int solution(vector<int> priorities, int location)
{
	int answer = 0;
	priority_queue<int> pq;
	queue<pair<int, int>> q;

	for (int i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
		q.push(make_pair(priorities[i], i));
	}
	while (!q.empty()) {
		int i = q.front().first;
		int p = q.front().second;
		q.pop();

		if (p == pq.top()) {
			pq.pop();
			answer += 1;
			if (i == location) break;
		}
		else q.push(make_pair(i, p));

	}
	return answer;

}

int main() {
	vector<int> a = { 2,1,3,2 };
	vector<int> b = { 1,1,9,1,1,1,1 };
	cout << solution(b, 2);
	return 0;
}