#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int tmp = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1);
	cout << (tmp > 0 ? 1 : (tmp < 0) ? -1 : 0) << endl;
	return 0;
}