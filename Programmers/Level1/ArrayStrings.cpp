#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;

	sort(strings.begin(), strings.end());

	for (char ch = 'a'; ch <= 'z'; ch++) {
		for (int i = 0; i < strings.size() ; i++) {
			if (strings[i][n] == ch)
				answer.push_back(strings[i]);
		}
	}
	return answer;
}