#include <iostream>
using namespace std;

int main() {
	int n, m, result = 0;
	cin >> n >> m;

	int* arr = new int[n]; 
	for (int i = 0; i < n; i++) arr[i] = i + 1;
	int* num = new int[m];
	for (int i = 0; i < m; i++)  cin >> num[i];

	int curIndex = 0;
	for (int i = 0; i < m; i++) {
		
		// left 개수 확인 
		int leftCnt = 0, leftIndex = curIndex;
		while (arr[leftIndex] != num[i]) {
			leftIndex = leftIndex - 1 == -1 ? n - 1 : leftIndex - 1;
			if (arr[leftIndex] != 0) leftCnt++;
		}

		// right 개수 확인
		int rightCnt = 0, rightIndex = curIndex;
		while (arr[rightIndex] != num[i]) {
			rightIndex = rightIndex + 1 == n ? 0 : rightIndex + 1;
			if (arr[rightIndex] != 0) rightCnt++;
		}

		curIndex = leftIndex; // curIndex=rightIndex

		result += leftCnt < rightCnt ? leftCnt : rightCnt;
		arr[curIndex] = 0;

		int zeroCnt = 0;
		do {
			curIndex = curIndex + 1 == n ? 0 : curIndex + 1;
			zeroCnt++;
			if (zeroCnt > n) break;
		} while (arr[curIndex] == 0);
	}
	cout << result << endl;
	return 0;
}