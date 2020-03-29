#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) 
{
	

	sort(times.begin(), times.end());

	long long left = 0, right = (long long)times.back() * n;

	
	while (left <= right) 
	{
		long long mid = (left + right) / 2;	// 중간
		cout << left << ' ' << right << ' ' << mid << endl;

		long long people = 0;
		for (int i = 0; i < times.size(); i++) {
			people += mid / times[i];
		}
		if (people < n) 	left = mid+1; 
		else  right = mid-1; 
	}
	

	return left;
}

// testCase
int main() {
	cout << solution(6, { 7,10 });
	return 0;
}