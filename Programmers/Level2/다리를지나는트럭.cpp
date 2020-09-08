#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0, time = 1;
	queue<pair<int, int>> q; // 트럭의 무게, 들어온 시간


	int truck = 0, curWeight = 0;
	while (true) {
		if (truck == truck_weights.size() && q.empty()) break;

		if (truck != truck_weights.size()) {
			if (truck_weights[truck] + curWeight <= weight) {
				curWeight += truck_weights[truck];
				q.push(make_pair(truck_weights[truck], time));
				truck++;
			}
		}
		time++;

		if (!q.empty() && time - q.front().second >= bridge_length) {
			curWeight -= q.front().first;
			q.pop();
		}
	}
	return time;
}