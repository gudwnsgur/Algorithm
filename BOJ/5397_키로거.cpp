#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#define endl '\n'
using namespace std;


int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string str;
		list<char> pwd;
		list<char>::iterator buf = pwd.begin(); 
		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '<') {
				if (buf != pwd.begin()) buf--;
			}
			else if (str[i] == '>') {
				if (buf != pwd.end()) buf++;
			}
			else if (str[i] == '-') {
				if (buf != pwd.begin()) buf = pwd.erase(--buf);
			}
			else pwd.insert(buf, str[i]);
		}


		for (auto iter = pwd.begin(); iter != pwd.end(); iter++) {
			cout << *iter;
		}cout << endl;
	}


	return 0;
}

//  
