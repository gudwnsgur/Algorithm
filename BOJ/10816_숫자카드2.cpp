#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, num;
	cin >> n;
	
	map<int, int> M;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (M.find(num) != M.end()) M.find(num)->second++;
		else M.insert({ num, 1 });
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << (M.find(num) != M.end() ? M.find(num)->second : 0) << ' ';
	}
	cout << endl;
	return 0;
}
