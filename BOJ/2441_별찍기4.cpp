#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = n; i >= 1; i--) {
		for (int j = i; j < n; j++) cout << ' ';
		for (int j = 0; j < i; j++) cout << '*';
		cout << endl;
	}

	return 0;
}
