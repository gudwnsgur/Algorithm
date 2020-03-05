#include <string>
#include <vector>

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