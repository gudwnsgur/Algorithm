#include <string>
#include <vector>
using namespace std;

int LCM(int a, int b, int gcd) {
	return a*b / gcd;
}

int GCD(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int solution(vector<int> arr) {
	int answer = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		answer = LCM(answer, arr[i], GCD(answer, arr[i]));
	}
	return answer;
}