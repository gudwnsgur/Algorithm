#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 200000001;

	for (int i = 0; i < stones.size()-k+1; i++) {
		int curMax = 0;
		int maxIndex = i;
		for (int j = i; j < i+k; j++) {
			if (curMax < stones[j]) {
				curMax = stones[j];
				maxIndex = j;
			}
		}
		if (i + 1 < maxIndex) i = maxIndex - 1;
		if(answer>curMax) answer = curMax;
	}
	return answer;
}