#include <iostream>
#define endl '\n'
using namespace std;

int arr[6] = { 500, 100, 50, 10, 5, 1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int money, cnt = 0;
	cin >> money;
	money = 1000 - money;
	while (money > 0) {
		for (int i = 0; i < 6; i++) {
			if (money >= arr[i]) {
				money -= arr[i];
				break;
			}
		}
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}