#include <vector>
#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;


int main() {
	int n;
	int a, b, c;
	int prevMinDp[3] = { 0, 0, 0 }, prevMaxDp[3] = { 0, 0, 0 };
	int minDp[3] = { 0, 0, 0 }, maxDp[3] = { 0, 0, 0 };
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;

		for (int j = 0; j < 3; j++) {
			prevMinDp[j] = minDp[j];
			prevMaxDp[j] = maxDp[j];
		}
		
		maxDp[0] = max(prevMaxDp[0] + a, prevMaxDp[1] + b);
		maxDp[1] = max(prevMaxDp[0] + a, max(prevMaxDp[1] + b, prevMaxDp[2] + c));
		maxDp[2] = max(prevMaxDp[1] + b, prevMaxDp[2] + c);


		minDp[0] = min(prevMinDp[0] + a, prevMinDp[1] + b);
		minDp[1] = min(prevMinDp[0] + a, min(prevMinDp[1] + b, prevMinDp[2] + c));
		minDp[2] = min(prevMinDp[1] + b, prevMinDp[2] + c);

	}
	cout << max(maxDp[0], max(maxDp[1], maxDp[2])) << ' ' << min(minDp[0], min(minDp[1], minDp[2])) << endl;
	return 0;
}
