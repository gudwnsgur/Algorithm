#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int answer = 0;
	vector<int> num;
	vector<bool> op;
	
	int standard = 0;
	for (int i = 0; i < str.size()-1; i++) {
		if (str[i+1] == '+' || str[i+1] == '-' || i == str.size() - 1) {
			num.push_back(stoi(str.substr(standard, i - standard + 1)));
			op.push_back(str[i + 1] == '+' ? true : false);
			i++;
			standard = i + 1;
		}
	}
	num.push_back(stoi(str.substr(standard, str.size() - standard)));
	
	answer += num[0];
	int i = 0;
	for (; i < op.size(); i++) {
		if (op[i]) answer += num[i + 1];
		else break;
	}
	for (i; i < op.size(); i++) {
		answer -= num[i + 1];
	}

	cout << answer << endl;
	return 0;
}

