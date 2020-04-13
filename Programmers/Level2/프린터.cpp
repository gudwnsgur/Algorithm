#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<int> priorities, int location) {
	deque <pair<int, int>> dq;
	int max=0;
	int answer = 0;

	for (int i = 0; i < priorities.size(); i++) {
		if (priorities[i] > max) max = priorities[i];
		dq.push_back(make_pair(priorities[i],i)); 
	} 
	// 2,0 , 1,1,  3,2,  2,3

	while(!dq.empty()) {
		answer++;
		while (max != dq.front().first) 
		{
			int pri = dq.front().first;
			int loc = dq.front().second;

			dq.pop_front();
			dq.push_back(make_pair(pri, loc));
		}
		if (location == dq.front().second) return answer;
		dq.pop_front();
		max = 0;

		for (int i = 0; i < dq.size(); i++) {
			if (dq[i].first > max) max = dq[i].first;
		}	
	}


	return answer;
}

// 2, 1, 3, 2
