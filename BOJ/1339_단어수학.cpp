#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#define endl '\n'
using namespace std;

int n;
bool compare(pair<int, string> a, pair<int, string> b) {
	return a.first > b.first;
}

int main() {
	int result = 0;
	cin >> n;
	vector<pair<int, string>> v;
	vector<int> alphabet(26);

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(make_pair(str.size(), str));
	}
	sort(v.begin(), v.end(), compare);

	int maxLength = v[0].first;
	for (int i = maxLength; i >= 1; i--) {
		for (int j = 0; j < v.size(); j++) {
			if (v[j].first >= i) 
				alphabet[v[j].second[v[j].first - i] - 65] += pow(10, i - 1);
		}
	}
	sort(alphabet.begin(), alphabet.end(), greater<int>());
	for (int i = 0, num=9 ; i < alphabet.size(); i++, num--) {
		result += alphabet[i] * num;
	}
	cout << result << endl;
	return 0;
}