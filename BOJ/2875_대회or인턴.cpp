#include <iostream>
using namespace std;
int main() {
	int w, m, k;
	cin >> w >> m >> k;
	
	while (k-- > 0) {
		w >= m * 2 ? w-- : m--;
	}
	cout << (w>m*2?m:w/2) << endl;

	return 0;
}