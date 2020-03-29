/*
 LIS (최장증가수열) 알고리즘

 vector lis 에 들어있는 값은 실제 값과 무관하다.
*/


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int number[1001]{ 0, };

int main() {
	vector<int> lis;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> number[i];

	lis.push_back(number[1]);

	for (int i = 2; i <= n; i++) {
		if (number[i] > lis.back()) {
			lis.push_back(number[i]);
		}
		else if (number[i] < lis.back()) {
			lis[lower_bound(lis.begin(), lis.end(), number[i]) - lis.begin()] = number[i];
		}
	}
	cout << lis.size();

	return 0;
}