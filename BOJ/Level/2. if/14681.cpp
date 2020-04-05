#include <iostream>
using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	cout << ((x>0) ? ((y>0) ? 1 : 4 ) : ((y>0) ? 2 : 3));
	return 0;
}