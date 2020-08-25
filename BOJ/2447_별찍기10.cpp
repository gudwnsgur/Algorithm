#include <iostream>
using namespace std;
char star[2188][2188];

void draw(int n, int x, int y) {
	if(n!=1) {
		for (int i = x + n/3 ; i < x + (n/3)*2 ; i++) {
			for (int j = y +n/3 ; j < y + (n/3)*2; j++) {
				star[i][j] = ' ';
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != 1 || y != 1)
					draw(n / 3, (n / 3)*i + x, (n / 3)*j + y);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star[i][j] = '*';
		}
	}
    
	draw(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << star[i][j];
		}
		cout << endl;
	}
	return 0;
}