#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ull unsigned long long
#define endl '\n'
using namespace std;

ull solve(ull a, ull b, ull c) {
	if (b == 0) return 1;
	if (b == 1) return a%c;

	ull tmp = solve(a, b / 2, c);
	if (b & 1) return (tmp * tmp)%c * a%c;
	else return (tmp * tmp)%c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ull a, b, c;
	cin >> a >> b >> c;
	cout << solve(a, b, c) << endl;
	return 0;
}
