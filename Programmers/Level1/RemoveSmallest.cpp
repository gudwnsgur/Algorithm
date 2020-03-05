#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;

	if (arr.size() == 1) {
		arr.clear();
		arr.push_back(-1);
		return arr;
	}
	int smallest = arr[0];
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < smallest) smallest = arr[i];
	}
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != smallest) answer.push_back(arr[i]);
	}
	return answer;
}


vector<int> solution2(vector<int> arr) {
	vector<int> answer;

	int min = *min_element(arr.begin(), arr.end());
	int max = *max_element(arr.begin(), arr.end());
	// max, min 찾기

	int pos = find(arr.begin(), arr.end(), min)-arr.begin() ;
	// 원하는 원소의 index 찾기

	arr.erase(arr.begin() + pos);
	// 원하는 index 원소 지우기

	return arr.empty() ? vector<int>(1,-1) : arr ;
}