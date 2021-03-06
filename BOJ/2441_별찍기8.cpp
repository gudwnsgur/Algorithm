#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
	int n, star = 1;
	cin >> n;
	int space = n * 2 - 2;
	
	for (int i = 0; i < n; i++, star+=1, space-=2) {
		for (int j = 0; j < star; j++) cout << '*';
		for (int j = 0; j < space; j++) cout << ' ';
		for (int j = 0; j < star; j++) cout << '*';
		cout << endl;
	}
	n--;
	space = 2, star = n ;
	for (int i = 0; i < n; i++, star -= 1, space+=2) {
		for (int j = 0; j < star; j++) cout << '*';

		for (int j = 0; j < space; j++) cout << ' ';
		for (int j = 0; j < star; j++) cout << '*';
		cout << endl;
	}

	return 0;
}
