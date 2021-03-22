#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int cnt = 0, start = 1;
	int length = 2 * w + 1;

	for (int i = 0; i < stations.size(); i++) {
		int end = stations[i] - w - 1;
		if (start <= end) {
			int cur = end - start + 1;
			cnt += (cur%length ? cur/length + 1 : cur/length );
		}
		start = stations[i] + w + 1;
	}
	if (start <= n) {
		int cur = n - start + 1;
		cnt += (cur%length ? cur / length + 1 : cur / length);
	}
	return cnt;
}


