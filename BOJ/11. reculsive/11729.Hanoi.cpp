#include <iostream>
#include "math.h"
using namespace std;

void hanoi(int n, int from, int by, int to)
{
	if (n == 1) cout << endl << from << " " << to;
	else
	{
		hanoi(n - 1, from, to, by);
		cout << endl << from << " " << to;
		hanoi(n - 1, by, from, to);
	}
}

int main() {
	int N;
	cin >> N;
	cout << pow(2, N) - 1;
	hanoi(N, 1, 2, 3);
	return 0;
}