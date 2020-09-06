#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;
	for (int i = 0; i < arr.size(); i++) 
		if (!(arr[i] % divisor)) answer.push_back(arr[i]);

	if (!answer.size()) answer.push_back(-1);
	sort(answer.begin(), answer.end());
	return answer;
}