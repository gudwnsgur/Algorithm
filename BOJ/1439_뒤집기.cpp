#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

int main() {
	string str;
	cin >> str;
	char s = str[0];
	int zero= 0, one = 0;
	
	for (int i = 0; i < str.size();) {
		char cur = str[i];

		cur == '1' ? one++ : zero++;
		while (cur == str[i]) i++;
	}
	cout << min(zero, one) << endl;
	return 0;
}


