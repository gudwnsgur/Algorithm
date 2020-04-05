#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
		return a.first < b.first;
}

int main() {
	int n;
	cin >> n;

	vector<pair<int, string>> person;
	int age;
	string name;
    
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		person.push_back(make_pair(age, name));
	}
	stable_sort(person.begin(), person.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << person[i].first << ' ' << person[i].second << "\n";
	}
	return 0;
}