#include <iostream>
#include <math.h>
#define endl '\n'
using namespace std;
int result = 0;

void recursion(int n, int x, int y) {
	if (n == 0) return;
	int length = pow(2, n);

	if (x < length / 2 && y < length / 2) {
		recursion(n - 1, x, y);
	}
	else if (x < length / 2 && y >= length / 2) {
		result += (length / 2)*(length / 2);
		recursion(n - 1, x , y - length/2);
	}
	else if (x >= length / 2 && y < length / 2) {
		result += (length / 2)*(length / 2) * 2;
		recursion(n - 1, x - length/2, y );

	}
	else {
		result += (length / 2)*(length / 2) * 3;
		recursion(n - 1, x - length/2, y - length/2);

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x, y;
	cin >> n >> x >> y;
	recursion(n, x, y);
	cout << result << endl;
	return 0;
}