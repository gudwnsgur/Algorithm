#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> m;
int cnt = 0, inf = 987654321;

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	for (int i = 0; i < gems.size(); i++) {
		if (m.find(gems[i]) != m.end()) continue;
		m.insert({ gems[i], cnt});
		cnt++;
	}
	vector<int> dp(cnt, inf);
	int localCnt = 0;
	int i = 0;
	for (; i <gems.size(); i++) {
		if (dp[m.find(gems[i])->second] == inf) 
			localCnt++;
		dp[m.find(gems[i])->second] = i;
		
		if (localCnt == cnt) break;
	}
	int minLength = *max_element(dp.begin(), dp.end()) - *min_element(dp.begin(), dp.end());
	int minIndex = i;

	for (; i<gems.size(); i++) {
		dp[m.find(gems[i])->second] = i;
		int localLength = *max_element(dp.begin(), dp.end()) - *min_element(dp.begin(), dp.end());
		if (minLength > localLength) {
			minIndex = i;
			minLength = localLength;
		}
	}

	cout << minIndex << ' ' << minLength << endl;
	answer.push_back(minIndex - minLength + 1);
	answer.push_back(minIndex + 1);
	return answer;
}