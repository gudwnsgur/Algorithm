#include <iostream>
using namespace std;

int arr[51];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n == 1 || (n==2 && arr[0]!=arr[1])) cout << "A" << endl;
	else {
		if (arr[1] == arr[0]) {
			for (int i = 0; i < n; i++) {
				if (arr[i] != arr[0]) {
					cout << "B" << endl;
					return 0;
				}
			}
			cout << arr[0] << endl;
			return 0;
		}
		int a, b;
		a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
		b = arr[1] - arr[0] * a;
		for (int i = 0; i < n-1; i++) {
			if (arr[i] * a + b != arr[i + 1]) {
				cout << "B" << endl;
				return 0;
			}
		}

		cout << arr[n - 1] * a + b << endl;
	}
	return 0;
}
