#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution1(vector<int> arr) 
{
    arr.erase(unique(arr.begin(),arr.end()), arr.end());
    return arr;
}

vector<int> solution2(vector<int> arr)
{
	if (arr.size() == 1) return arr;

	vector<int> answer;
	answer.push_back(arr[0]);

	for (int i = 1; i < arr.size(); i++) {
		if (answer.back() != arr[i]) 
			answer.push_back(arr[i]);
	}
	return answer;
}

