#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

int solve(string str, string src) {
	int res = 0;
	for (int i = 0; i < str.size(); i++) {
		if (i + src.size() > str.size()) break;
		if (str.substr(i, src.size()) == src) {
			res++;
			i += src.size()-1;
		}
	}
	return res;
}


int main() {
	string dest, src;
	getline(cin, dest);
	getline(cin, src);
	cout << solve(dest, src) << endl;
	return 0;
}
