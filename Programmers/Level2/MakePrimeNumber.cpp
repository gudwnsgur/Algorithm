#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


bool isPrimeNumber(int num) {
	if (num == 0 || num == 1) return false;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int solution(vector<int> nums) {
	int answer = 0;

	for (int i = 0; i < nums.size() - 2; i++) {
		for (int j = i + 1; j < nums.size() - 1; j++) {
			for (int k = j + 1; k < nums.size(); k++) {
				if(isPrimeNumber(nums[i]+nums[j]+nums[k])) answer++;
			}
		}
	}

	return answer;
}
int main() 
{
	cout << solution({ 1,2,7,6,4 });
	
	return 0;
}