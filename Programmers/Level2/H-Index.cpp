#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int maxCitations = -1;

	for (int i = 0; i < citations.size(); i++) 
		if (citations[i] > maxCitations) maxCitations = citations[i];
	
	for (int i = maxCitations; i >= 0; i--) 
	{
		int greater = 0, less = 0;
		for (int j = 0; j < citations.size(); j++) {
			if (citations[j] >= i) greater++;
			if (citations[j] <= i-1) less++;
		}
		if (i <= greater && i>= less) return i;
	}
}
int main() {
	vector<int> testCase = { 3,0,6,1,5 };
	cout << solution(testCase);
	return 0;
}