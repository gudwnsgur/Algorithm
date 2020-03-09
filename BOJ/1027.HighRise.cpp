#include <iostream>
#include <algorithm>
using namespace std;

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
		
		double leftGradient = (i!=0) ? ((double)building[i] - (double)building[i - 1]) : 0;
		for (int j = i - 2; j >= 0; j--) 
		{
			if (leftGradient - 0.000000001 > ( ((double)building[i] - building[j]) / ((double)i - j)) ){
				cnt++;
				leftGradient = ((double)building[i] - building[j]) / ((double)i - j);
			}
		}
		
		double rightGradient = (i!=N-1) ? ((double)building[i + 1] - (double)building[i]) : 0;
		for (int j = i + 2; j < N; j++) {
			if (rightGradient + 0.000000001 < ((double)building[j] - building[i]) / ((double)j - i)) {
				cnt++;
				rightGradient = ((double)building[j] - building[i]) / ((double)j - i);
			}
		}
		result = max(result, cnt);
	}
	
	cout << result << endl;
	return 0;
}

// 1 5 3 2 6 3 2 6 4 2 5 7 3 1 5
// 2 4 4 4 6 4 4 6 4 4 4 4 3 3 3 

