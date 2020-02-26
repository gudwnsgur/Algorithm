#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	int n;
	cin >> n;
	vector<string> v;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end() ,compare);
	unique(v.begin(), v.end());

	for (string line : v) {
		cout << line << "\n";
		if (line == v.back()) break;
	}
	return 0;
}