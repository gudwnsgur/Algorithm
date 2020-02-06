#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int testCase;
	double x1, y1, r1, x2, y2, r2;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double sub = sqrt( pow(fabs(y2 - y1),2)+pow(fabs(x2 - x1),2));
		if (x1 == x2 && y1 == y2 && r1 == r2)
			cout << "-1\n";
		else if ((r1 + r2) < sub || fabs(r1 - r2) > sub) {
			cout << "0\n";
		}
		else if (r1 + r2 == sub || fabs(r1 - r2) == sub)
			cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}