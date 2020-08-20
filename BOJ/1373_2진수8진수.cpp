#include <iostream>
#include <string>
#include <math.h>
#define LENGTH 1000000
using namespace std;


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int result=0;
	string binary;
	char oct[LENGTH];
	cin >> binary;

	int loc = 0;
	for (int i = binary.size() - 1; i >= 0; i-=3, loc++) {
		if(i>1) oct[loc] = binary[i]-48 + 2*(binary[i-1]-48) + 4*(binary[i-2]-48) + 48;
		else if (i == 1)  oct[loc] = binary[i] - 48 + 2 * (binary[i - 1] - 48)  + 48;
		else oct[loc] = binary[i];
	}
	for (int i = loc-1; i >= 0; i--) cout << oct[i];
	cout << endl;

	return 0;
}