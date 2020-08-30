#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int main() {
	int cur=0, result=0;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			cur++;
		} 
		else {
			if (str[i - 1] == '(') {
				cur--;
				result += cur;
			}
			else {
				result++;
				cur--;
			}
		}
 	}
	cout << result << endl;
	return 0;
}