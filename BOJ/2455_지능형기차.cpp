#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[4][2];
	int answer = 0, cur = 0;
	for (int i = 0; i < 4; i++) {
		cin >> arr[i][0];
		cur -= arr[i][0];

		cin >> arr[i][1];
		cur += arr[i][1];

		answer = max(answer, cur);
	}
	cout << answer << endl;
	return 0;
}
