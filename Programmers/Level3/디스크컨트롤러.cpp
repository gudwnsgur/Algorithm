#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

bool compare(vector<int> a, vector<int> b) {
	if (a[0] == b[0]) return a[1] < b[1];
	return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
	sort(jobs.begin(), jobs.end(), compare);
	int answer = 0, time = 0, jobIndex = 0;
	while (true) {
		if (jobIndex >= jobs.size() && pq.empty()) break;
		while (jobIndex < jobs.size() && jobs[jobIndex][0] <= time) {
			pq.push({ jobs[jobIndex][1], jobs[jobIndex][0] });
			jobIndex++;
		}
		if (pq.empty() && jobIndex < jobs.size()) {
			time = jobs[jobIndex][0];
			pq.push({jobs[jobIndex][1], jobs[jobIndex][0]});
			jobIndex++;
		}
		time += pq.top().first;
		answer += time - pq.top().second;
		pq.pop();
	}
	return answer/jobs.size();
}
int main() {
	cout << solution({ {0,4}, {0,3}, {0,2}, {500,4}});
	return 0;
}