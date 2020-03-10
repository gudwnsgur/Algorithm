#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(int n) {
	int* fibo= new int[n+1];
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= n; i++)
		fibo[i] = (fibo[i - 2] + fibo[i - 1])%1234567;
	return fibo[n] ;
}
int main() {
	while (1) {
		int n;
		cin >> n;
		cout << solution(n) << endl;
	}
	return 0;
}