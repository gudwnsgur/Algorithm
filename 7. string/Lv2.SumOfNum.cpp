#include <iostream>
using namespace std;

int main() {
	int N, sum;
	cin >> N;
	sum = 0;
	
	char* str = new char[N];
	cin >> str;
	for (int i = 0; i < N; i++) {
		sum += str[i] - '0';
	}

	cout << sum;
	return 0;
}