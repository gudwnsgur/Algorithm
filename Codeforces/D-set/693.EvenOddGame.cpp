#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#define endl '\n'
using namespace std;

string solution(int n) {
	long long alice = 0, bob = 0;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<long long>());

	for (int i = 0; i < n; i++) {
		if (!(i % 2) && !(v[i] % 2)) alice += v[i];
		else if (i % 2 && v[i] % 2) bob += v[i];
	}
	return alice > bob ? "Alice" : alice < bob ? "Bob" : "Tie";
}
int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n;
		cin >> n;
		cout << solution(n) << endl;
	}
	return 0;
}
