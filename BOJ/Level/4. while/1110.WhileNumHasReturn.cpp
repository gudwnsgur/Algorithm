#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int input, tmp = 0;
	int ten, one, res=0;
	int cycle = 0;

	cin >> input;
	tmp = input;

	 while (1) {
        if (tmp < 10)    ten = 0;
        else    ten = tmp / 10;
        one = tmp % 10;
 
        res = ten + one;
		cycle++;
 
        ten = tmp % 10;
        one = res % 10;
        tmp = (ten * 10) + one;
 
        if (tmp == input)
            break;
    }
	cout << cycle;
	return 0;
}
