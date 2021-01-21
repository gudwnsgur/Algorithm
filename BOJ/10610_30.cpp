#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;
	
	int sum = 0;
	bool possible = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0') possible = true;
		sum += str[i] - 48;
	}
	if (sum % 3 || !possible) {
		cout << -1 << endl;
		return 0;
	}

	sort(str.begin(), str.end());
	for (int i = str.size() - 1; i >= 0; i--) {
		cout << str[i];
	}
	cout << endl;
	return 0;
}
