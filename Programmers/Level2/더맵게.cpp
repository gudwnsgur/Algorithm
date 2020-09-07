#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int> pq;
	for (int i = 0; i < scoville.size(); i++) pq.push(scoville[i] * -1);

	while (true) {
		if (pq.size() == 1 && pq.top() * -1 <= K) return -1;
		if (pq.top() * -1 >= K) return answer;
		int firstMin = pq.top();	pq.pop();
		int secondMin = pq.top();	pq.pop();

		pq.push(firstMin + (secondMin * 2));
		answer++;
	}
}
int main() {

	vector<int> v{ 123, 556, 22,21, 52,61, 7, 83,101, 32 };
	cout << solution(v, 10);

	return 0;
}