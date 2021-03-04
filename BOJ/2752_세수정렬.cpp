#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	int a, b, c;
	int aa, bb, cc;

	cin >> a >> b >> c;
	aa = max(a, max(b, c));
	cc = min(a, min(b, c));
	bb = ( (a != aa && a != cc) ? a : (b != aa && b != cc ? b : c));

	cout << cc << ' ' << bb  << ' '<< aa<< endl;
	return 0;
}

