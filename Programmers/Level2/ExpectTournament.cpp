#include <iostream>
using namespace std;

int solution(int n, int a, int b)
{
	int answer = 1;

	while (true) {
		if ((a % 2 && b == a + 1) || (b % 2 && a == b + 1)) break;
		answer++;
		a = a%2 ? a/2+1 : a/2; 
		b = b%2 ? b/2+1 : b/2;
	}
	return answer;
}

// Test Case;
int main() {
	cout << solution(8, 4, 7);
	return 0;
}