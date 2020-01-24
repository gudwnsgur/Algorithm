#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num1, num2, num3;
	int multi;

	int *arr = new int[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = 0;
	}

	cin >> num1 >> num2 >> num3;
	multi = num1 * num2*num3;

	do {
		int unit = multi % 10;
		arr[unit]++;
		multi = multi / 10;
	} while (multi > 0.1);

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << "\n";
	}
	return 0;
}
