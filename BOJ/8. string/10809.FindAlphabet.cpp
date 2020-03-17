#include <iostream>
#include <string>
using namespace std;

int main() {
	int testCase;
	cin >> testCase;


	for (int i = 0; i < testCase; i++) {
		int R;
		string str;
		cin >> R;
		cin >> str;

		for (int j = 0; j < str.length() ; j++) {
			for (int k = 0; k < R; k++) {
				cout << str[j];
			}
		}
		cout << "\n";
	}
	return 0;
}