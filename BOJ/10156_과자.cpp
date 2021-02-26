#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	int k, n, m;
	cin >> k >> n >> m;
	cout << ( k*n - m > 0  ? k*n - m : 0  )<< endl;
	return 0;
}


