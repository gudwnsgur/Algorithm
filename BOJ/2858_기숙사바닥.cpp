#include <iostream>
using namespace std;

int main() {
	int R, B, L, W;
	cin >> R >> B;
	
	int LplusW, LW;
	LplusW = R / 2 + 2;
	LW = B - 4 + 2 * (R / 2 + 2);

	for (int i = 3; i <= LplusW; i++) {
		if (i*(LplusW - i) == LW) {
			cout << LplusW - i << ' ' << i << endl;
			break;
		}
	}
	return 0;
}