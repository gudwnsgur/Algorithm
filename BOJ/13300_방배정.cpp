#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<pair<int, int>> cnt(7, { 0, 0 });

int main() {
	int n, k, res = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int sex, grade;
		cin >> sex >> grade;
		sex ? cnt[grade].second++ : cnt[grade].first++;
	}

	for (int i = 1; i <= 6; i++) {
		if (cnt[i].first != 0) 	res += ( cnt[i].first % k ) ?  cnt[i].first / k + 1 : cnt[i].first/k;
		if (cnt[i].second != 0) res += (cnt[i].second % k ) ? cnt[i].second/ k + 1 : cnt[i].second / k;
	}

	cout << res << endl;
	return 0;
}
