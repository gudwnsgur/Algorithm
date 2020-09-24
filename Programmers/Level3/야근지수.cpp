#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

ll dp[20001] = { 0, };
long long solution(int n, vector<int> works) {
	ll sum = 0, answer = 0;
	int size = works.size();
	for (int i = 0; i < works.size(); i++) sum += works[i];
	if (sum <= (ll)n) return 0;

	sort(works.begin(), works.end());
	ll tmp = sum - (ll)(works[0] * size);

	int i = 0;
	if (tmp == n) return works[0] * works[0] * works.size();
	if (tmp > n) {
		i = works.size() - 2;
		for (int j = 1; i >= 0; i--, j++) {
			dp[i] = dp[i + 1] + (works[i + 1] - works[i])*j;
			if (dp[i] > n) break;
		}
		
		for (int j = 0; j <= i; j++) {
			answer += works[j] * works[j];
		}
		i++;
		sum = 0, tmp = 0;
		for (int j = i; j < size; j++) sum += works[j];
		size = works.size() - i;
		tmp = sum - (ll)(works[i] * size);
	}

	answer += ((n - tmp) % size) * (works[i] - ((n - tmp) / size + 1))
		* (works[i] - ((n - tmp) / size + 1));
	answer += (size - ((n - tmp) % size)) * (works[i] - ((n - tmp) / size))
		* (works[i] - ((n - tmp) / size));
	return answer;
}