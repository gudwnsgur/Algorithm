#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> weight) {
	sort(weight.begin(), weight.end());

	int answer = 1;
	if (weight[0] != 1) return 1;

	for (int i = 1; i < weight.size(); i++) {
		if (answer + 1 < weight[i]) break;
		answer += weight[i];
	}	// 1 1 2 3 6 7 30
	return answer+1;
}