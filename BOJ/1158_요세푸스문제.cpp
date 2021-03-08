#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#define endl '\n'
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	list<int> l;
	vector<int> res;

	for (int i = 1; i <= n; i++) l.push_back(i);
	list<int>::iterator it = l.begin();

	for (int i = 0; i < n; i++) {
		int tmp = k-1;
		while (tmp--) {
			it++;
			if (it == l.end()) it = l.begin();
		}

		res.push_back(*it);
		it = l.erase(it);
		if (it == l.end()) it = l.begin();
	}

	cout << "<";
	for (int i = 0; i < res.size()-1; i++) cout << res[i] << ", ";
	cout << res[res.size()-1] << ">" << endl;
	return 0;
}

