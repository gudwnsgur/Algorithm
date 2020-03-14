#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	sort(people.begin(), people.end());
	int leftIndex = 0, rightIndex = people.size() - 1;


	while (leftIndex < rightIndex+1) {
		if (people[leftIndex] + people[rightIndex] <= limit)
			leftIndex++;
		rightIndex--;
		answer++;
	}
	
	return answer;
}

int main() {
	vector<int> v = { 20,30,20,30,20, 70, 80 , 40, 56, 20 , 10, 90 ,43};
	cout << solution(v, 100);
	return 0;
}