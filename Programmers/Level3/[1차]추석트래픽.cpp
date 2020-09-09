#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
int result = 0;
vector<pair<int, char>> v;
int solution(vector<string> lines) {
	int answer = 0;
	for (int i = 0; i < lines.size(); i++) {
		string str = lines[i];
		int endTime = stoi(str.substr(11, 2)) * 60 * 60 * 1000 + stoi(str.substr(14, 2)) * 60 * 1000 +
					  stoi(str.substr(17, 2)) * 1000 + stoi(str.substr(20, 3));

		double diff =  (stod(str.substr(24, str.size() - 23))) * 1000;
		
		int startTime = endTime - (int)diff;
		v.push_back(make_pair(startTime, 's'));
		v.push_back(make_pair(endTime+999, 'e'));
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == 's') cnt++;
		else cnt--;
		result = max(result, cnt);
	}
	return result;
}
int main() {
	string a = "12.315";
	cout << stod(a);
	return 0;

}