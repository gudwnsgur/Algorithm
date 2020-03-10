#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	for (int i = 0; i < phone_book.size(); i++) {
		for (int j = 0; j < phone_book.size(); j++) {
			if (phone_book[i].size() > phone_book[j].size()) break;
			else if (i != j && phone_book[i] == (phone_book[j].substr(0, phone_book[i].size())))
			{
				cout << phone_book[j].substr(0, phone_book[i].size());
				return false;

			}
		}
	}
	return answer;
}

int main() {
	vector<string> pb = { "123","456","789" };
	cout << solution(pb);
	return 0;
}