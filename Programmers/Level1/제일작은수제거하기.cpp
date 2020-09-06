#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
	vector<int> answer;

	int min = *min_element(arr.begin(), arr.end());
	int pos = find(arr.begin(), arr.end(), min)-arr.begin() ;
	arr.erase(arr.begin() + pos);

	return arr.empty() ? vector<int>(1,-1) : arr ;
}