#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	int cnt = food_times.size();
	for (int i = 0; i < food_times.size(); i++) {
		food_times[i] -= (int)k/cnt;
	}
	
	for (int i = 0, last = (int)k % cnt; last > 0 ; i++, last--) {
		food_times[i]--;
	}
	for (int i = 0; i < food_times.size(); i++) cout << food_times[i] << ' ';
	cout << endl;
	return answer;
}

int main() {
	cout << solution({ 3,1,2,6,2,1,6,7,2,3 }, 32);
	return 0;
}
// 3 1 2 
// 1, 2, 3, 1, 3, 
