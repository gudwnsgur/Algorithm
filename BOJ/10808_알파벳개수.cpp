#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int alphabet[26] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) alphabet[str[i]-97]++;
	for (int i = 0; i < 26; i++) cout << alphabet[i] << ' ';
	return 0;
}