#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	int n, num, y = 0, m = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		y += ((num / 30) + 1) * 10;
		m += ((num / 60) + 1) * 15;
	}
	if (y == m) cout << "Y M " << y << endl;
	else if (y > m) cout << "M " << m << endl;
	else cout << "Y " << y << endl;
}
