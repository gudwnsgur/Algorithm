#include <vector>
#include <algorithm>
#include <iostream>
#define ll unsigned long long
using namespace std;

vector<int> house;
vector<int> diff;
int n, c;

bool possible(int length) {
	int cur = 0, res = 1;
	for (int i = 0; i < diff.size(); i++) {
		cur += diff[i];
		if (cur >= length) {
			cur = 0;
			res++;
		}
	}
	return res >= c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;
	house = vector<int>(n);
	for (int i = 0; i < house.size(); i++) cin >> house[i];
	sort(house.begin(), house.end());
	for (int i = 1; i < house.size(); i++) {
		diff.push_back(house[i] - house[i - 1]);
	}


	if (c == 2) {
		cout << house[house.size() - 1] - house[0] << endl;
		return 0;
	}

	int left = 1, right = house[house.size() - 1] - house[0];
	int result = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (possible(mid)) {
			result = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << result << endl;
	return 0;
}

