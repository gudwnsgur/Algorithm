#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;
	sort(routes.begin(), routes.end());

	vector<int> tmp = routes.front();
	for (int i = 1; i < routes.size(); i++) {
		if (tmp[1] > routes[i][1]) tmp = routes[i];
		if (tmp[1] < routes[i][0]) {
			tmp = routes[i];
			answer++;
		}
	}
	return answer;
}

// testCase
int main() {
	vector<vector<int>> a = { { {-20,15},{-14,-5},{-18,-13},{-5,-3} } };
	vector<vector<int>> b = { {3,4}, {2,9}, {6,12}, {3,8}, {9,13},{5,11} ,{1,3} ,{7,9} };
 	cout << solution(a) << endl;
	cout << solution(b) << endl;
	return 0;
}