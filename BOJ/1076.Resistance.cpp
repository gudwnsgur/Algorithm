#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int main() {

	string resistanceTable[10] = { "black", "brown", "red", "orange", "yellow", 
								   "green", "blue", "violet", "grey", "white"   };

	string color[3];
	cin >> color[0] >> color[1] >> color[2];

	int pos[3];
	for (int i = 0; i < 10; i++) {
		if (color[0] == resistanceTable[i]) pos[0] = i;
		if (color[1] == resistanceTable[i]) pos[1] = i;
		if (color[2] == resistanceTable[i]) pos[2] = i;
	}

	long long resistance = (long long)((long long) pos[0]*10 + pos[1] ) * pow(10, pos[2]) ;
	cout << resistance;
	return 0;
}

