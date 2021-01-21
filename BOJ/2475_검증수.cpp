#include <iostream>
using namespace std;

int main() {
	int arr[5];
	int answer = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		answer += arr[i] * arr[i];
	}
	cout << answer % 10 << endl;
	return 0;
}
