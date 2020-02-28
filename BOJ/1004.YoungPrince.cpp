#include <iostream>
#include <math.h>
using namespace std;

double distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n, cnt = 0;
		cin >> n;
		int* planet = new int[3];


		for (int i = 0; i < n; i++) {
			cin >> planet[0] >> planet[1] >> planet[2];
			if (((double)planet[2] > (distance(planet[0], planet[1], x1, y1)) &&
				(double)planet[2] < (distance(planet[0], planet[1], x2, y2)))
				||
				((double)planet[2] < (distance(planet[0], planet[1], x1, y1)) &&
				(double)planet[2] > (distance(planet[0], planet[1], x2, y2))))
				cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}