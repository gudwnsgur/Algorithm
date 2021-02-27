#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;


bool compare(string a, string b) {
	if (a.size() == b.size()) {
		int aCnt = 0, bCnt = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] >= '0' && a[i] <= '9') aCnt += a[i] - '0';
			if (b[i] >= '0' && b[i] <= '9') bCnt += b[i] - '0';
		}
		if (aCnt != bCnt) return aCnt < bCnt;
		else {
			return a < b;
		}

	}
	else return a.size() < b.size();
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<string> str(n);
	for (int i = 0; i < n; i++) cin >> str[i];

	sort(str.begin(), str.end(), compare);
	
	for (int i = 0; i < n; i++) cout << str[i] << endl;
	return 0;
}


