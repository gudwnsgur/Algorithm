#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;

int solve(int a, int b) {
	string str;
	int res = 0, least = a/b, activate = 1;
	cin >> str;

	int firstOne = str.size()+1, lastOne = -1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '1') {
			firstOne = i;
			break;
		}
	}
	if (firstOne == str.size() + 1) return 0;

	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] == '1') {
			lastOne = i;
			break;
		}
	}
	

	for (int i = firstOne; i <= lastOne; i++) {
		if (str[i] == '0') {
			int zeroCnt = 0;
			for (; i <= lastOne && str[i] =='0'; i++) zeroCnt++;
			i--;

			if (zeroCnt <= least) res += zeroCnt*b;
			else activate++;		
		}
	}

	return res + activate * a;
}

int main() {
	int testCase, a, b;
	cin >> testCase;
	while (testCase--) {
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
	return 0;
}
