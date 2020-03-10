#include <iostream>
#include <algorithm>
using namespace std;

int CCW(long long x1, long long y1, long long  x2, long long  y2, long long  x3, long long  y3) {
	long long tmp = x1 * y2 + x2 * y3 + x3 * y1;
	tmp = tmp - y1 * x2 - y2 * x3 - y3 * x1;

	if (tmp > 0) return 1; // 1 -> 2 -> 3 가 반시계방향
	if (tmp == 0) return 0; // 1==2==3 일직선
	if (tmp < 0) return -1; // 1 -> 2 -> 3 가 시계방향
}
int main() {
	int N;
	cin >> N;

	int* building = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> building[i];
	}

	int result = 0;
	for (int i = 0; i < N ; i++) 
	{
		int cnt;
		if (i == 0 || i == (N - 1)) cnt = 1;
		else cnt = 2;

		long long maxIndex = (long long)i - 1;
		for (int j = i - 2; j >= 0; j--)
		{
			//cout << i << ' ' << maxIndex << ' ' << j << endl;
			if (CCW(i,building[i],maxIndex,building[maxIndex], j, building[j]) == -1 ) {
				cnt++;
				maxIndex = j;
			}
		}
		maxIndex = (long long)i + 1;
		for (int j = i + 2; j < N; j++)	{
			//cout << i << ' ' << maxIndex << ' ' << j << endl;
			if (CCW(i, building[i], maxIndex, building[maxIndex], j, building[j]) == 1) {
				cnt++;
				maxIndex = j;
			}
		}
		result = max(result, cnt);
	}
	
	cout <<  result ;
	return 0;
}

// 1 5 3 2 6 3 2 6 4 2 5 7 3 1 5
// 2 4 4 4 6 4 4 6 4 4 4 4 3 3 3 

