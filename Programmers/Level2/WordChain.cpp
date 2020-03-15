#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	vector<string> history { words[0] };
	int i = 1;

	for(; i<words.size(); i++) {
		
		if (words[i - 1][words[i - 1].size() - 1] != words[i][0]) break;	// 오답 검사
		
		int pos = find(history.begin(), history.end(), words[i]) - history.begin();
;		if (pos != i) break;	// 중복 검사
		history.push_back(words[i]);	
	}

	if (i == words.size()) {
		answer.push_back(0);  
		answer.push_back(0);
	}	
	else {
		answer.push_back(i%n+1); 
		answer.push_back(i/n+1);
	} 

	return answer;
}

// Test Case
int main() {
	vector<string> v;
	string input;
	int n, numOfWords;

	cin >> n >> numOfWords;
	for (int i = 0; i < numOfWords; i++) {
		cin >> input;
		v.push_back(input);
	}
	vector<int> vi = solution(n, v);
	for (int i = 0; i < vi.size(); i++) {
		cout << vi[i] << ' ';
	}


	return 0;
}