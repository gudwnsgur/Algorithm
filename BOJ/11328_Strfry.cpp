#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

vector<int> cnt1, cnt2;

int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		string s1, s2;
		cin >> s1 >> s2;

		cnt1 = vector<int>(26, 0);
		cnt2 = vector<int>(26, 0);
		for (int i = 0; i < s1.size(); i++) cnt1[s1[i] - 'a']++;
		for (int i = 0; i < s2.size(); i++) cnt2[s2[i] - 'a']++;

		bool pos = true;
		for (int i = 0; i < 26; i++) {
			if (cnt1[i] != cnt2[i]) {
				pos = false;
				break;
			}
		}
		cout << ( pos ? "Possible" : "Impossible") << endl;
	}
	return 0;
}
