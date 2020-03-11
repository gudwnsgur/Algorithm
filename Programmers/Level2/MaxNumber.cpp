#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int a, int b) {
	return stoi(to_string(a) + to_string(b)) > stoi(to_string(b) + to_string(a));
}
string solution(vector<int> numbers) {
	string answer = "";
	sort(numbers.begin(), numbers.end(), cmp);
	
	for (int i = 0; i < numbers.size(); i++) {
		answer += to_string(numbers[i]);
	}
	return answer;
}
int main() {
	vector<int> v = {30, 35, 3, 5 };
	cout << solution(v);
	return 0;
}