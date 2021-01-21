#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int rule[10][4] = { {0, 0, 0, 0},
						{1, 1, 1, 1},
						{6, 2, 4, 8},
						{1, 3, 9, 7},
						{6, 4, 6, 4},
						{5, 5, 5, 5},
						{6, 6, 6, 6},
						{1, 7, 9, 3},
						{6, 8, 4, 2},
						{1, 9, 1, 9}};

	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int a, b;
		cin >> a >> b;

		
		cout <<  ( rule[a % 10][b % 4] ? rule[a % 10][b % 4] : 10)  << endl;
	}
	return 0;
}
