#include <iostream>
#include <string>
#include <list>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;
	list<char> lt;
	for (int i = 0; i < str.size(); i++) lt.push_back(str[i]);

	int n;
	auto cursor = lt.end();
	cin >> n;
	cin.ignore();
	while (n--) {
		string edit;
		getline(cin, edit);

		if (edit[0] == 'L') {
			if (cursor != lt.begin()) cursor--;
		}
		else if (edit[0] == 'D') {
			if (cursor != lt.end()) cursor++;
		}
		else if (edit[0] == 'B') {
			if (cursor != lt.begin()) {
				cursor--;
				cursor = lt.erase(cursor);
			}
		}
		else { // 'P'
			lt.insert(cursor, edit[2]);
		}
	}

	for (cursor = lt.begin(); cursor != lt.end(); cursor++) cout << *cursor;
	cout << endl;
	return 0;
}