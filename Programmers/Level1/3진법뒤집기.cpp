#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
	int answer = 0;
	string v;

	while (n > 0) {
		v.push_back((n % 3 + 48));
		n /= 3;
	}
	
	for (int i = v.size() - 1, j=1; i >= 0; i--, j*=3) {
		answer += (v[i] - 48)*j;
	}
	return answer;
}

int main() {
	cout << solution(125) << endl;
	return 0;
}

