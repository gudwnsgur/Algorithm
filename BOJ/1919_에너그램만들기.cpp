#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

vector<int> cnt1(26, 0), cnt2(26, 0);

int main() {
	int res = 0;
	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 0; i < str1.size(); i++) cnt1[str1[i] - 'a']++;
	for (int i = 0; i < str2.size(); i++) cnt2[str2[i] - 'a']++;


	for (int i = 0; i < 26; i++) res += abs(cnt1[i] - cnt2[i]);

	cout << res << endl;
	return 0;
}
