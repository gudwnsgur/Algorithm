#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int solution(vector<vector<string>> clothes) {
	vector<int> cnt;
	vector<string> kinds;
	int result = 1;

	for (int i = 0; i < clothes.size(); i++) {
		int index = find(kinds.begin(), kinds.end(), clothes[i][1]) - kinds.begin();
		if (index == kinds.size()) {
			cout << index << ' ' << clothes[i][1] << endl;
			cnt.push_back(1);
			kinds.push_back(clothes[i][1]);
		}
		else cnt[index]++;
		
	}
	for (int i = 0; i < cnt.size(); i++) {
		result *= cnt[i] + 1;
	}
	return result-1;
}
int main() {
	vector<vector<string>> s;
	s.push_back({ "","aa" });
	s.push_back({ "","bb" });
	s.push_back({ "","aa" });
	s.push_back({ "","c" });

	cout << solution(s) << endl;
	return 0;
}