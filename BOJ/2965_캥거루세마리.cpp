#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int result = (c - b > b - a) ? c - b - 1 : b - a - 1;
	cout << result << endl;
	return 0;
}