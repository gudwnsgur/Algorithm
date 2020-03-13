#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

// solution_One : 시간 초과 코드
// 매 반복문마다 오름차순 정렬
int solution_One(vector<int> scoville, int K) {
	int answer = 0;

	while (true) {
		if (scoville.size() == 1 && scoville[0] < K) return -1;

		sort(scoville.begin(), scoville.end(), greater<int>());
		if (scoville.back() >= K) return answer;

		int firstMin = scoville.back(); scoville.pop_back();
		int secondMin = scoville.back(); scoville.pop_back();

		scoville.push_back(firstMin + (secondMin * 2));
		answer++;
	}
}

// solution_Two : 통과 코드 
// 우선순위 큐 이용 (우선순위를 반대로 하기 위해 연산시 -1을 곱함)
int solution_Two(vector<int> scoville, int K) {
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
// Test Code 
int main() {

	vector<int> v{ 123, 556, 22,21, 52,61, 7, 83,101, 32 };
	int testCode;
	cin >> testCode;

	cout << solution_One(v, testCode) << endl;
	cout << solution_Two(v, testCode) << endl;

	return 0;
}