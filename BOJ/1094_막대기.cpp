#include <iostream>
#define endl '\n'
using namespace std;

int main() {
	int n, res = 0;
	cin >> n;
	while (n > 0) {
		res += (n % 2 ? 1 : 0);
		n /= 2;
	
	}
	cout << res << endl;
	return 0;
}

