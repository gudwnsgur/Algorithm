#include <iostream>
#include "math.h"
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	unsigned int x, y;
	int n;
	cin >> n;
	for (int i=0; i<n ; i++) {
		cin >> x >> y;
		double n = sqrt(y-x);

		if (n == (int)n) 
			cout << n * 2 - 1 << "\n"; 
		else if (n > (double)((int)n + 0.5)) 
			cout << (int)n * 2 + 1 << "\n";
		else 
			cout << (int)n * 2 << "\n";
	}
	return 0;
}
