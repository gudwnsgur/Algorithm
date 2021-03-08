#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<int> cnt(10, 0);

int main() {
	int num;
	cin >> num;

	if (!num) {
		cout << 1 << endl;
		return 0;
	}
	while (num > 0) {
		cnt[num % 10]++;
		num /= 10;
	}

	cnt[6] = cnt[9] = (  (cnt[6] + cnt[9]) % 2  ? (cnt[6]+cnt[9])/2 + 1 : (cnt[6] + cnt[9]) / 2);
	cout << *max_element(cnt.begin(), cnt.end()) << endl;
	return 0;
}
