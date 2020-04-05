#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;

	int non = N;
	do {
		count++;
		non /= 10;
	} while (non >= 1);

	int* arr = new int[count];
	for (int i = 0; i < count; i++) {
		arr[i] = N % 10;
		N /= 10;
	}
	sort(arr, arr + count, greater<int>());

	for (int i = 0; i < count; i++) {
		cout << arr[i];
	}
	return 0;
}