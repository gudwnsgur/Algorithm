#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	int n, space = 0;
	cin >> n;
	int star = n*2 - 1;
	
	for (int i = 0; i < n; i++, star-=2, space++) {
		for (int j = 0; j < space; j++) cout << ' ';
		for (int j = 0; j < star; j++) cout << '*';
		cout << endl;
	}

	return 0;
}
