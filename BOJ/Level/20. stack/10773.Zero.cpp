#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int number, result=0;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> number;
		if (number) {
			result += number;
			s.push(number);
		}
		else {
			result -= s.top();
			s.pop();
		}
	}
	cout << result;
	return 0;
}