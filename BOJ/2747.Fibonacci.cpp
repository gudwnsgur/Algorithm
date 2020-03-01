#include <iostream>
using namespace std;

int solution(int first, int second, int n) {
	if(n==0) return first;
	return solution(second, first + second, --n);
}

int main() {
	int N;
		cin >> N;
		cout << solution(0, 1, N);
	
	return 0;
}